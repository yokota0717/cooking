#include "Usingheaders.h"
extern const int
SCREEN_WIDIH,
SCREEN_HEIGHT,
quarterNote = 461,		//四分音符の長さ(ms)
halfNote = 923,			//二分音符の長さ(ms)
dottedHalfNote = 1385;	//符点2分


bool File::LoadScore()
{

	//譜面読み込み
#if _DEBUG
	ifstream ifs_noteJust("./ScoreData/Scoredata_Debug.csv");	//音符のジャストの判定タイミング(※ファイルに書く時間は小数点以下まで書くこと)
	ifstream ifs_type("./ScoreData/type_Debug.csv");				//音符の画像とSEのデータ
	ifstream ifs_appaer("./ScoreData/dir.csv");			    //左右の方向のデータ
#else
	ifstream ifs_noteJust("./ScoreData/Scoredata1.csv");	//音符のジャストの判定タイミング(※ファイルに書く時間は小数点以下まで書くこと)
	ifstream ifs_type("./ScoreData/type.csv");				//音符の画像とSEのデータ
	ifstream ifs_appaer("./ScoreData/dir.csv");			    //左右の方向のデータ
#endif

	
	//開かなかったらエラー
	if (!ifs_noteJust || !ifs_type || !ifs_appaer)
	{
		return false;
	}

	string s_judeg;
	string s_ID;
	string s_dir;
	//ループ用変数
	int j = 0;
	int i = 0;
	int d = 0;

	while (getline(ifs_noteJust, s_judeg, '\n'))
	{
		//文字列をint型に変換
		judge[j] = stoi(s_judeg);
		++j;
		if (i > noteMax)
		{
			break;
		}
	}
	while (getline(ifs_type, s_ID, '\n'))
	{
		//文字列をint型に変換
		id[i] = stoi(s_ID);
		++i;
		if (i > noteMax)
		{
			break;
		}
	}
	while (getline(ifs_appaer, s_dir, '\n'))
	{
		//文字列をint型に変換
		dir[d] = stoi(s_dir);
		++d;

		if (d > noteMax)
		{
			break;
		}
	}

	return true;

}

void Note::SetScore(int id, Note& note, const File& file) {
	note.data.judge = file.judge[id];
	note.data.ID = file.id[id];
	//note.data.d = (file.dir[id] == 1) ? RIGHT : LEFT;
	switch (file.dir[id])
	{
	case LEFT:
		note.data.d = LEFT;
		break;
	case RIGHT:
		note.data.d = RIGHT;
		break;
	case BOTTOM:
		note.data.d = BOTTOM;
		break;
	}
	//算出する
	//N_Type
	SetN_Type(note);
	//appear
	SetAppearTime(note);
	//Vec start,dir,end
	SetBezierData(note);
	//speed
	SetSpeed(note);

}

void Note::SetN_Type(Note& note){
	switch (note.data.ID) {
	case 1:
	case 2:
	case 5:
		note.move.note_type = N_one;
		break;
	case 3:
	case 4:
	case 6:
		note.move.note_type = N_rest;
		break;
	case 7:
		note.move.note_type = N_mouse;
		break;
	}
}
void Note::SetAppearTime(Note& note) {
	switch (note.move.note_type) {
	case N_one:
		note.data.appear = note.data.judge - quarterNote;
		break;
	case N_rest:
		note.data.appear = note.data.judge - halfNote;
		break;
	case N_mouse:
		note.data.appear = note.data.judge - dottedHalfNote;
		//note.data.appear = note.data.judge - halfNote;
		break;
	}
}

void Note::SetBezierData(Note& note) {
	switch (note.data.d) {
	case LEFT:
		note.move.start.x = float(-imageSizeX / 2);
		note.move.start.y = float(SCREEN_HEIGHT / 2);
		note.move.end.x = 630.0f / 2.0f;	//Player.cpp　check　の座標をコピペ、画像の位置関係で要変更
		note.move.end.y = 280.0f;
		note.move.dir.x = (note.move.end.x - note.move.start.x)/ 2.0f;
		//dir.yはN_Typeによって変わる
		note.move.dir.y = (note.move.note_type == N_one) ? float(SCREEN_HEIGHT / 3) : float(SCREEN_HEIGHT / 5);  //要変更
		break;
	case RIGHT:
		note.move.start.x = float(SCREEN_WIDIH + imageSizeX / 2);
		note.move.start.y = float(SCREEN_HEIGHT / 2);
		note.move.end.x = 630.0f;	//Player.cpp　check　の座標をコピペ、画像の位置関係で要変更
		note.move.end.y = 280.0f;
		note.move.dir.x = note.move.end.x + float((note.move.start.x - note.move.end.x) / 2);
		//dir.yはN_Typeによって変わる
		note.move.dir.y = (note.move.note_type == N_one) ? float(SCREEN_HEIGHT / 3) : float(SCREEN_HEIGHT / 5);  //要変更
		break;
	case BOTTOM:
		note.move.start.x = float(SCREEN_WIDIH + imageSizeX / 2);
		note.move.start.y = float(500);
		note.move.end.x = float(0);	//左端
		note.move.end.y = 500.0f;		
		note.move.dir.x = 760;
		//dir.yはN_Typeによって変わる
		note.move.dir.y = 400.0f;
		break;
	}
}

void Note::SetSpeed(Note& note) {
	switch (note.move.note_type) {
	case N_one:
		note.move.speed = float(((630 / 2) - (-imageSizeX / 2)) / quarterNote);	//1msで何ピクセル移動するか
		break;
	case N_rest:
		note.move.speed = float(((630 / 2) - (-imageSizeX / 2)) / halfNote);	//1msで何ピクセル移動するか
		break;
	case N_mouse:
		note.move.speed = -0.2f;	//1msで何ピクセル移動するか
		//note.move.speed = float(((630 / 2) - (-imageSizeX / 2)) / halfNote);	//1msで何ピクセル移動するか
		break;
	}
}		

//バッド判定
bool Note_Check_Bad(int c, int j)
{
	static constexpr int Input_Reception_MAX = 60;
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
	static constexpr int GOOD = 65;
	
	if (c >= j - GOOD &&
		c <= j + GOOD &&
		Key(KEY_INPUT_Z)==1)
	{
		Player::Effect_On();
		return true;
		
	}
	return false;
}
//クール判定
bool Note_Check_Cool(int c, int j)
{
	static constexpr int COOL = 10;

	if (c >= j - COOL &&
		c <= j + COOL &&
		Key(KEY_INPUT_Z) == 1)
	{
		Player::Effect_On();
		
		return true;
	}
	return false;
}
//オート
bool Auto(int c, int j)
{
	if (c >= j-12 )
	{
		return true;
	}
	return false;
}
int& Score(int s)
{
	static int score;
	
	score += s;
	return score;
}
bool Note::Initialize()
{
	int check[7];
	check[0] = LoadDivGraph("./Graph/carrot.png",  4, 4, 1, 100, 100, move.pic_carrot);
	check[1] = LoadDivGraph("./Graph/onion.png",   4, 4, 1, 100, 100, move.pic_onion);
	check[2] = LoadDivGraph("./Graph/cabbage.png", 4, 4, 1, 100, 100, move.pic_cabbage);
	check[3] = LoadDivGraph("./Graph/potato.png",  4, 4, 1, 100, 100, move.pic_potato);
	check[4] = LoadDivGraph("./Graph/brory.png",   4, 4, 1, 100, 100, move.pic_broccoli);
	check[5] = LoadDivGraph("./Graph/tomato.png",  4, 4, 1, 100, 100, move.pic_tomato);
	check[6] = LoadDivGraph("./Graph/rat.png",     4, 4, 1, 100, 100, move.pic_mouse);
	move.animeCnt = 0;
	move.state = off;
	bez.bez = move.start;
	appearSEplayed = false;
	data.hit = Normal;
	start = false;
	for (int i = 0; i < 7; ++i)
	{
		if (check[i] == -1)
		{
			return false;
		}
	}
	
	return true;
}


void Note::Update()
{
	Sound GetSound();
	auto sound = GetSound();

	data.current = GetSoundCurrentTime(sound.BGM);
	//開始直後だとdata.appearに-461が入ってしまうので強引に出現処理に入らないようにしている(´・ω・`)
	if (start == false && data.appear > 0)
	{
		start = true;
	}
	//出現
	if (start == true && !appearSEplayed && move.state == off && data.current >= data.appear)
	{
		sound.PlaySE(appear);
		appearSEplayed = true;
		move.state = come;
	}

	if (move.state != off) {
		//移動
		bez.BezTimeUpdate(move.note_type, data.current, data.appear);
		move.pos = bez.MoveBezier2(move.start, move.dir, move.end);

	}
		if (move.state == come) {
		//判定
		switch (data.hit)
		{
		case Normal:
			//オートモード(デバッグ用、リリース時には消す) 
#if _DEBUG
			if (Auto(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);
				Player::Set_Cut();
				data.hit = hit;
				move.state = cut;
				Player::Effect_On();
				Player::Player_Animation(data.d);
				Score(10);
			}
#endif
			//
			if (Note_Check_Cool(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);
				Score(10);
				data.hit = hit;
				move.state = cut;
				Player::Player_Animation(data.d);
			}
			if (Note_Check_Good(data.current, data.judge) && data.hit == Normal)
			{
				sound.PlaySE(data.ID);

				Score(5);
				data.hit = hit;
				move.state = cut;
				Player::Player_Animation(data.d);
			}
			//判定時間内に入力がない場合
			else if (Note_Check_Bad(data.current, data.judge) && data.hit == Normal)
			{
				data.hit = miss;
			}
			break;

		case hit:
			data.hit = Normal;
			break;

		case miss:
			data.hit = Normal;
			break;

		default:

			break;
		}

	}

		if (move.state == cut) {
			move.animeCnt++;
		}

		if (move.pos.y >= 500) {
			move.state = off;
		}
		else if (data.d == BOTTOM && move.pos.x <= 0) {
			move.state = off;
		}


}

void Note::Draw()
{

	SetDrawMode(DX_DRAWMODE_BILINEAR);	//実数ピクセル補間
	if (move.state == come)	//死ぬ前の音符
	{
		switch (data.ID)
		{
		case carrot:  DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_carrot[0],   true); break;
		case onion:   DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_onion[0],    true); break;
		case tomato:  DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_tomato[0],   true); break;
		case cabbage: DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_cabbage[0],  true); break;
		case potato:  DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_potato[0],   true); break;
		case broccoli:DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_broccoli[0], true); break;
		case mouse:   DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_mouse[0],    true); break;
		}
		
	}
	if (move.state == cut)	//音符が死んだらアニメーション
	{
		int animTable[] = { 0,1,2,3 };

		switch (data.ID)
		{
		case carrot:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_carrot[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case onion:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_onion[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case tomato:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_tomato[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case cabbage:
			if ((move.animeCnt / 3) <= 3) {
				DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_cabbage[animTable[move.animeCnt / 3]], true);
			}
			else {
				move.state = off;
			}
			break;
		case potato:
		if ((move.animeCnt / 3) <= 3) {
			DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_potato[animTable[move.animeCnt / 3]], true);
		}
		else {
			move.state = off;
		}
		break;
		case broccoli:
		if ((move.animeCnt / 3) <= 3) {
			DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_broccoli[animTable[move.animeCnt / 3]], true);
		}
		else {
			move.state = off;
		}
		break;
		case mouse:
			if ((move.animeCnt / 3) <= 3) 
			DrawRotaGraphF(move.pos.x, move.pos.y, 1.0, 0.0, move.pic_mouse[3], true);
			else
			move.state = off;
			break;
		}
		
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);	//解除

#if _DEBUG
	Sound GetSound();
	auto sound = GetSound();
	DrawFormatString(0, 80, GetColor(0, 0, 0), "現在の再生位置%d", GetSoundCurrentTime(sound.BGM));
#endif

}

void Note::Fin()
{
	InitGraph();
}
