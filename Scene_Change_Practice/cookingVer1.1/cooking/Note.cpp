#include "Usingheaders.h"

namespace Note {

	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540,
		QUARTER_NOTE = 461;				//リズムの最小単位(4分音符)
	double	second = 60.0;
	Note note;
	TYPE se_type;
	constexpr int num = 500;		//とりあえず音符は500が上限
	POS start, dir, end;			//曲線の開始点、方向点、終点座標
	

	bool LoadScore()
	{
		//譜面読み込み
		ifstream ifs_noteJust("./ScoreData/Scoredata.csv");		//音符のジャストの判定タイミング
		ifstream ifs_type("./ScoreData/type.csv");				//音符の画像とSEのデータ
		
		note.notenum = 0;
		note.IDnum = 0;
		//開かなかったらエラー
		if (!ifs_noteJust || !ifs_type)
		{
			return false;
		}
		
		
		string s_just;
		string s_type;
		string s_appear;
		int i = 0;
		int j = 0;
		int s = 0;
		

		while(getline(ifs_noteJust,s_just,'\n'))
		{
			//文字列をint型に変換
			note.just_Note[i] = stoi(s_just);
			++i;
			if (i > num)
			{
				break;
			}
		}
		while (getline(ifs_type, s_type, '\n'))
		{
			//文字列をint型に変換
			note.ID[j] = stoi(s_type);
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
		note.notenum = 0;


		note.dir.x = fabs(note.start.x - note.end.x) / 2 + note.end.x;
		note.dir.y = 100;

		
		
		if (cheak == -1)
		{
			return false;
		}
		return true;
	}

	void Update()
	{
		
		Sound GetSound();
		auto sound = GetSound();
		
		note.current = GetSoundCurrentTime(sound.BGM);
		//出現
		/*if (note.current >= appear_Time)
		{
			sound.PlaySE(appear);
			++note.notenum;
			
		}*/
		//判定
		if (note.current >= note.just_Note[note.IDnum])
		{
			sound.PlaySE(carrot);
			++note.IDnum;

		}
		

		//BezierCurve2(&note, note.start, note.dir, note.end);

		


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
		DrawFormatString(0, 40, GetColor(0, 0, 0), "出現音符数:%d", note.notenum);
		DrawFormatString(0, 20, GetColor(0, 0, 0), "判定済みの音符:%d", note.IDnum);
		
	}

	void Fin()
	{
		for (int i = 0; i < 4; ++i)
		{
			DeleteGraph(note.picHandle[i]);
		}

	}
}
