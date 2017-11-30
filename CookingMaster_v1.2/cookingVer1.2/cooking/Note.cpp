#include "Usingheaders.h"
static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;

static constexpr int Input_Reception_MAX = 50;


bool Note::LoadScore()
{

	//譜面読み込み
	ifstream ifs_noteJust("./ScoreData/Scoredata.csv");		//音符のジャストの判定タイミング
	ifstream ifs_type("./ScoreData/type.csv");				//音符の画像とSEのデータ
	ifstream ifs_appaer("./ScoreData/appear.csv");


	
	//開かなかったらエラー
	if (!ifs_noteJust || !ifs_type || !ifs_appaer)
	{
		return false;
	}

	string s_judeg;
	string s_ID;
	string s_appear;
	//ループ用変数
	int j = 0;
	int i = 0;
	int a = 0;

	while (getline(ifs_noteJust, s_judeg, '\n'))
	{
		//文字列をint型に変換
		data.judge[j] = stoi(s_judeg);
		++j;
		if (i > 100)
		{
			break;
		}
	}
	while (getline(ifs_type, s_ID, '\n'))
	{
		//文字列をint型に変換
		data.ID[i] = stoi(s_ID);
		++i;
		if (i > 100)
		{
			break;
		}
	}
	while (getline(ifs_appaer, s_appear, '\n'))
	{
		//文字列をint型に変換
		data.appear[a] = stoi(s_appear);
		++a;
		if (a > 100)
		{
			break;
		}
	}

	return true;

}
//バッド判定
bool Note_Check_Bad(int c, int j)
{
	if (c >= j - Input_Reception_MAX &&
		c >= j + Input_Reception_MAX)
	{
		return true;
	}
	return false;
}
//グッド判定
bool Note_Check_Good(int c, int j)
{
	static constexpr int GOOD = 45;
	
	if (c >= j - GOOD &&
		c <= j + GOOD &&
		Key(KEY_INPUT_Z) == 1)
	{
		return true;
	}
	return false;
}
//クール判定
bool Note_Check_Cool(int c, int j)
{
	static constexpr int COOL = 8;

	if (c >= j - COOL &&
		c <= j + COOL &&
		Key(KEY_INPUT_Z) == 1)
	{
		return true;
	}
	return false;
}
bool Note::Initialize()
{
	
	int check = LoadDivGraph("./Graph/carrot.png", 4, 4, 1, 100, 100, move.picHandle);
	move.pos.x = SCREEN_WIDIH + 50;
	move.pos.y = SCREEN_HEIGHT / 2;
	move.animeCnt = 0;
	move.time = 0;
	move.note_type = N_one;
	move.speed = 17.0f * 2.2f;
	move.start.x = move.pos.x;
	move.start.y = move.pos.y;
	move.end.x = SCREEN_WIDIH / 2;
	move.end.y = SCREEN_HEIGHT / 2 + 160;
	move.state = come;
	move.dir.x = fabs(move.start.x - move.end.x) / 2 + move.end.x;
	move.dir.y = 100;

	data.a_cnt = 0;
	data.ID_cnt = 0;
	data.j_cnt = 0;
	data.hit = Normal;

	if (check == -1)
	{
		return false;
	}

	return true;

}



void Note::Update()
{
	Sound GetSound();
	auto sound = GetSound();

	data.current = GetSoundCurrentTime(sound.BGM);
	//出現
	if (data.current >= data.appear[data.a_cnt])
	{
		sound.PlaySE(appear);
		++data.a_cnt;

	}
	//判定
	switch (data.hit)
	{
	case Normal:
		if (Note_Check_Cool(data.current, data.judge[data.j_cnt]) && data.hit == Normal)
		{
			sound.PlaySE(data.ID[data.ID_cnt]);
			data.score += 10;
			data.hit = hit;
		}
		if (Note_Check_Good(data.current, data.judge[data.j_cnt]) && data.hit == Normal)
		{
			sound.PlaySE(data.ID[data.ID_cnt]);

			data.score += 2;
			data.hit = hit;
		}
		//判定時間内に入力がない場合
		else if (Note_Check_Bad(data.current, data.judge[data.j_cnt]) && data.hit == Normal)
		{
			data.hit = miss;
		}
	
			break;
	case hit:
		++data.j_cnt;
		++data.ID_cnt;
		data.hit = Normal;
		break;
	case miss:
		++data.j_cnt;
		++data.ID_cnt;
		data.hit = Normal;
		break;

	default:

		break;
	}

}

void Note::Draw()
{

	if (move.state == come)	//死ぬ前の音符
	{
		DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.picHandle[0], true);
	}
	if (move.state == cut)	//音符が死んだらアニメーション
	{
		DrawRotaGraph(int(move.pos.x), int(move.pos.y), 1.0, 0.0, move.picHandle[move.animeCnt / 2], true);
	}

	Sound GetSound();
	auto sound = GetSound();


	//デバッグ用処理、リリース時には消す
	DrawFormatString(0, 0, GetColor(0, 0, 0), "得点（仮）:%d", data.score);
	DrawFormatString(0, 80, GetColor(0, 0, 0), "(サウンドクラス内)現在の再生位置%d", GetSoundCurrentTime(sound.BGM));
	DrawFormatString(0, 60, GetColor(0, 0, 0), "音符ID:%d", data.ID[data.ID_cnt]);
	DrawFormatString(0, 40, GetColor(0, 0, 0), "出現音符数:%d", data.a_cnt);
	DrawFormatString(0, 20, GetColor(0, 0, 0), "判定済みの音符:%d", data.j_cnt);

}

void Note::Fin()
{
	for (int i = 0; i < 4; ++i)
	{
		DeleteGraph(move.picHandle[i]);
	}
}