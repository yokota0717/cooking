#include "Usingheaders.h"

namespace Note {

	static const int
	SCREEN_WIDIH = 960,
	SCREEN_HEIGHT = 540;
	double	second = 60.0;
	Note note;
	SETYPE se_type;
	constexpr int num = 500;		//とりあえず音符は500まで
	POS start, dir, end;  //曲線の開始点、方向点、終点座標


	bool LoadScore()
	{
		//譜面読み込み
		ifstream ifs_apper("./ScoreData/test.csv");
		ifstream ifs_type("./ScoreData/type.csv");
		note.notenum = 0;
		note.notetype = 0;
		//開かなかったらエラー
		if (!ifs_apper || !ifs_type)
		{
			return false;
		}
		
		
		string s_appper;
		string s_type;
		int i = 0;
		int j = 0;
		note.apper_note[num];

		while(getline(ifs_apper,s_appper,'\n'))
		{
			//文字列をint型に変換
			note.apper_note[i] = stoi(s_appper);
			++i;
			if (i > num)
			{
				break;
			}
		}
		while (getline(ifs_type, s_type, '\n'))
		{
			//文字列をint型に変換
			note.play_note_type[j] = stoi(s_type);
			++j;
			if (j > num)
			{
				break;
			}
		}
		return true;
	}

	bool Initialize()
	{

		int cheak = LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, note.picHandle);
		note.pos.x = SCREEN_WIDIH + 50;
		note.pos.y = SCREEN_HEIGHT / 2;
		note.Cnt = 0;
		note.animeCnt = 0;
		note.time = 0;
		note.type = one;
		note.speed = 17.0f * 2.2f;
		note.start.x = note.pos.x;
		note.start.y = note.pos.y;
		note.end.x = SCREEN_WIDIH / 2;
		note.end.y = SCREEN_HEIGHT / 2 + 160;
		note.state = come;
		

		note.dir.x = fabs(note.start.x - note.end.x) / 2 + note.end.x;
		note.dir.y = 100;

	
		if (cheak == -1)
		{
			return false;
		}
		return true;
	}

	void Updata()
	{
		Sound GetSound();
		auto sound = GetSound();

		note.current = GetSoundCurrentTime(sound.BGM);

		if (note.current >= note.apper_note[note.notenum] && note.play_note_type[note.notetype] == 0)
		{
			++note.notenum;
			++note.notetype;
			sound.PlaySE(apper);
			
		}
		if (note.current >= note.apper_note[note.notenum] && note.play_note_type[note.notetype] == 1)
		{
			++note.notenum;
			++note.notetype;
			sound.PlaySE(carrot);
		}
		
		BezierCurve2(&note, note.start, note.dir, note.end);

		


	}

	void Draw()
	{

		if (note.state == come)	//死ぬ前の音符
		{
			DrawRotaGraph(int(note.pos.x), int(note.pos.y), 1.0, 0.0, note.picHandle[0], true);		
		}
		if (note.state == cut)	//音符が死んだらアニメーション
		{
			DrawRotaGraph(int(note.pos.x), int(note.pos.y), 1.0, 0.0, note.picHandle[note.animeCnt / 2], true);		
		}

		Sound GetSound();
		auto sound = GetSound();
		
		DrawFormatString(0, 80, GetColor(0, 0, 0), "(サウンドクラス内)現在の再生位置%d", GetSoundCurrentTime(sound.BGM));

		//DrawFormatString(0, 20, GetColor(0, 0, 0), "現在の再生位置%d", GetSoundCurrentTime(sound.PlayBGM(sound.BGM)));
		//DrawFormatString(0, 40, GetColor(0, 0, 0), "現在の再生位置%d", GetSoundTotalTime(sound.PlayBGM(sound.BGM)));
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note.picHandle[i]);
		}

	}
}
