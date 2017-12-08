#include "Usingheaders.h"
#include <math.h>

namespace Metronome {
	StaffAnimation staff;
	ChefAnimation chef;
	SubAnimation sub;

	int stf;
	int stfX;


	bool Initialize() {
		staff.BPM = 130;									//曲BPM
		staff.second = 60;								//1秒
		staff.singlfps = 1000 / 60;						//1フレーム分の時間[ms]

		staff.beat = 4;									//拍子
		staff.sibu = 1000 * (staff.second / staff.BPM);		//4分音符1個分の終了点

		staff.cnt = 1;
		staff.flag = true;
		stf = LoadGraph("./Graph/staff.png");
		stfX = 0;

		sub.flag = false;
		sub.x = -137;
		sub.y = 77;

		chef.chefY = 27;
		chef.anime = true;
		chef.aniCnt = 0;
		chef.mtr = LoadDivGraph("./Graph/chef.png", 3, 3, 1, 132, 243, chef.chef);
		chef.bg1 = LoadGraph("./Graph/bg.png");
		chef.bg2 = LoadGraph("./Graph/bg2.png");

		if (chef.mtr == -1 || chef.bg2 == -1)
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
			chef.anime = true;
			++staff.cnt;
		}

		if (staff.flag == false)
		{
			staff.sibu = 1000 * (staff.second / staff.BPM);
			staff.sibu *= staff.cnt;
			staff.flag = true;
		}

		if (sub.flag == true) 
		{
			sub.x += 2;
			if (sub.x >= 500)
			{
				sub.flag = false;
				sub.x = -137;
			}
		}

	}

	void Draw()
	{
		int ani[7] = { 2,2,1,1,0,1,2 }; //アニメーションにディレイをかけるために要素数を増やしている（実際は5こま）
		if (chef.anime == true) {
			if (chef.aniCnt < 9) {
				chef.chefY += 1;
			}
			else if (chef.aniCnt < 13) {
				chef.chefY -= 2;
			}
			else {
				chef.anime = false;
				chef.aniCnt = 0;
			}
			chef.aniCnt++;
		}
		
		DrawGraph(0, 0, chef.bg1, true);
		DrawGraph(sub.x, sub.y, stf, TRUE);
		DrawGraph(40, chef.chefY, chef.chef[ani[chef.aniCnt/2]], true);
		DrawGraph(0, 263, chef.bg2, true);

	}

	void Fin()
	{
		DeleteGraph(chef.bg2);
		for (int i = 0; i < 3; i++) {
			DeleteGraph(chef.chef[i]);
		}
	}

	void bgAni()
	{
		sub.flag = true;
	}

}