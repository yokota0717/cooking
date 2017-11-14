#include "Usingheaders.h"


using namespace Sound;
namespace Note {

	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	double	second = 60.0;
	Sound::SETYPE se_type;
	Note note_carrot;
	POS start, dir, end;  //曲線の開始点、方向点、終点座標

	bool Initialize()
	{
		int cheak = LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, note_carrot.picHandle);
		note_carrot.pos.x = SCREEN_WIDIH + 50;
		note_carrot.pos.y = SCREEN_HEIGHT / 2;
		note_carrot.Cnt = 0;
		note_carrot.animeCnt = 0;
		note_carrot.time = 0;
		note_carrot.type = one;
		note_carrot.speed = 17.0f * 2.2f;
		note_carrot.start.x = note_carrot.pos.x;
		note_carrot.start.y = note_carrot.pos.y;
		note_carrot.end.x = SCREEN_WIDIH / 2;
		note_carrot.end.y = SCREEN_HEIGHT / 2 + 160;
		note_carrot.state = come;

		note_carrot.dir.x = fabs(note_carrot.start.x - note_carrot.end.x) / 2 + note_carrot.end.x;
		note_carrot.dir.y = 100;

		note_carrot.BPM = 130;
		note_carrot.beat = 4;
		note_carrot.fourn_note = second / note_carrot.BPM - 0.04;
		note_carrot.eight_note = note_carrot.fourn_note / 2.0;
		note_carrot.BGM_time = note_carrot.Bar_end * 10.0;
		note_carrot.Bar_end = note_carrot.fourn_note * note_carrot.beat;
		/*note_carrot.hit_time = note_carrot.fourn_note * 2.0;*/
		//date.current_time = 0.0;
		PlaySE(apper);
		if (cheak == -1)
		{
			return false;
		}
		return true;
	}

	void Updata()
	{

		if (note_carrot.Cnt <= 0.0)
		{
			PlaySE(apper);		//仮処理。音符が出現する処理で鳴らす。最初の拍に合わせるとリズムとりやすいかも
		}
		
		if (note_carrot.state == come &&
			note_carrot.Cnt >= note_carrot.fourn_note
			)
		{
			
			PlaySE(carrot);
			note_carrot.state = cut;
			
		}
	
			
		/*if (date.BGM_time !=0 && date.current_time <= 0.0)
		{
			Initialize();
		}*/

		if (note_carrot.state == cut)
		{
			++note_carrot.animeCnt;
			if (note_carrot.Cnt >= note_carrot.Bar_end)
			{

				Initialize();
				note_carrot.Cnt = 0.0;

			}
		}
		note_carrot.BGM_time -= 1 / 60.0;
		note_carrot.Cnt += 1 / 60.0;
		BezierCurve2(&note_carrot, note_carrot.start, note_carrot.dir, note_carrot.end);
	}

	void Draw()
	{

		if (note_carrot.state == come)	//死ぬ前の音符
		{
			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[0], true);		//RotaGraphは座標が中心になる
		}
		if (note_carrot.state == cut)	//音符が死んだらアニメーション
		{
			DrawRotaGraph(int(note_carrot.pos.x), int(note_carrot.pos.y), 1.0, 0.0, note_carrot.picHandle[note_carrot.animeCnt / 2], true);		//RotaGraphは座標が中心になる
		}
		DrawFormatString(0, 0, GetColor(0, 0, 0), "経過時間（ミリ秒）%f", note_carrot.Cnt);
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note_carrot.picHandle[i]);
		}

	}
}
