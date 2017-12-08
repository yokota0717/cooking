#include "Usingheaders.h"

namespace Player {
	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	const int num = 7;
	Cock cock;
	Cock check;	//あたり判定の可視化に用いる、不要になったら削除
	Effect effect;
	Metronome::StaffAnimation staff;

	int Gstand[3];
	int GcutR[3];

	void Effect_draw();

	bool Initialize()
	{
		staff.BPM = 130;									//曲BPM
		staff.second = 60;								//1秒
		staff.singlfps = 1000 / 60;						//1フレーム分の時間[ms]

		staff.beat = 4;									//拍子
		staff.sibu = 1000 * (staff.second / staff.BPM);		//4分音符1個分の終了点

		staff.cnt = 1;
		staff.flag = true;

		cock.x = SCREEN_WIDIH/2;
		cock.y = SCREEN_WIDIH/4 + 90;
		cock.w = 512;
		cock.h = 512;
		check.x = 630;
		check.y = 280;
		cock.state = down;
		cock.animCnt = 0;

		effect.flag = false;
		effect.Cnt = 0;

		cock.picHandle[0] = LoadGraph("./Graph/512.png");
		LoadDivGraph("./Graph/stand.png", 3, 3, 1, 277, 502, Gstand);
		LoadDivGraph("./Graph/cutR.png", 3, 3, 1, 394, 495, GcutR);
		cock.e_pic=LoadGraph("./Graph/test_E.png", true);

		if (cock.picHandle[0] == -1)
		{
			return false;
		}
		return true;
	}

	void Update()
	{
		Sound GetSound();
		auto sound = GetSound();
		staff.current = GetSoundCurrentTime(sound.BGM);
		if (staff.current >= staff.sibu && staff.flag == true)
		{
			staff.flag = false;
			cock.flag = true;
			++staff.cnt;
		}

		if (staff.flag == false)
		{
			staff.sibu = 1000 * (staff.second / staff.BPM);
			staff.sibu *= staff.cnt;
			staff.flag = true;
		}

		if (Key(KEY_INPUT_RIGHT) >= 1)
		{
			cock.x += 5;
		}
		if (Key(KEY_INPUT_LEFT) >= 1)
		{
			cock.x -= 5;
		}
		if (Key(KEY_INPUT_Z) == 1)
		{
			cock.state = cut;
		}
	}

	void Draw()
	{
		int anime[14] = { 2,2,2,1,1,0,0,0,0,0,1,1,2,2 };
		if (cock.state == down && cock.flag == true) {
			++cock.animCnt;
			if (cock.animCnt > 7) {
				cock.state = up;
				cock.flag = false;
			}
		}
		if (cock.state == up && cock.flag == true) {
				++cock.animCnt;
				if (cock.animCnt > 13) {
					cock.animCnt = 0;
					cock.state = down;
					cock.flag = false;
				}
			}
		if (cock.state == up || cock.state == down)
		{
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, Gstand[anime[cock.animCnt]], true);
		}

		if (cock.state == cut) {
			int anime[num] = { 0,0,1,1,2,2,2 };
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, GcutR[anime[cock.animCnt / 2]], true);
			cock.animCnt++;
			if (effect.flag == true) { //エフェクト
				Effect_draw();
			}
			if (cock.animCnt > num * 2 - 1) {
				cock.state = down;
				cock.animCnt = 0;
			}
		}


		//あたり判定の可視化
		DrawCircle(check.x+10, check.y +100, 50, GetColor(255, 0, 0), false);			//右 (x+10,y+90)
		DrawCircle((check.x / 2)+10, check.y + 90, 50, GetColor(255, 0, 0), false);		//左 (x+10,y+90)
		DrawCircle(check.x - 145, check.y - 110, 50, GetColor(255, 0, 0), false);//上(x+10,y+90)
		DrawCircle(check.x - 145, check.y + 240, 50, GetColor(255, 0, 0), false);//下(x+10,y+90)
	}

	void Fin()
	{
		for (int i = 0; i < num; ++i)
		{
			DeleteGraph(cock.picHandle[i]);
		}
	}

	void Effect_On()
	{
		effect.flag = true;
	}

	void Effect_draw()
	{
		if (effect.Cnt <= 3) {
			DrawRotaGraph(check.x - 20, check.y + 80, 1.0, 0.0, cock.e_pic, true);
		}
		else
		{
			effect.flag = false;
			effect.Cnt = 0;
		}
		effect.Cnt++;
	}
}
