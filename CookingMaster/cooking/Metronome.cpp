#include "Usingheaders.h"
#include <math.h>

namespace Metronome {
	StaffAnimation staff;
	ChefAnimation chef;
	SubAnimation sub;

	void Sub_Animation();

	bool Initialize() {
		staff.BPM = 130;									//曲BPM
		staff.second = 60;								//1秒
		staff.singlfps = 1000 / 60;						//1フレーム分の時間[ms]

		staff.beat = 4;									//拍子
		staff.sibu = 1000 * (staff.second / staff.BPM);		//4分音符1個分の終了点

		staff.cnt = 1;
		staff.flag = true;

		sub.flag = false;
		sub.x = -175;
		sub.y = 77;
		sub.stf = LoadGraph("./Graph/staff.png");
		sub.aniCnt = 0;
		sub.state = up;
		LoadDivGraph("./Graph/food.png", 2, 2, 1, 76, 40, sub.food);

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
			sub.anime = true;
			++staff.cnt;
		}

		if (staff.flag == false)
		{
			staff.sibu = 1000 * (staff.second / staff.BPM);
			staff.sibu *= staff.cnt;
			staff.flag = true;
		}

		Sub_Animation();

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
		DrawGraph(sub.x + 91, sub.y + 130, sub.food[sub.foodNum], true);
		DrawGraph(sub.x, sub.y, sub.stf, true);
		DrawGraph(40, chef.chefY, chef.chef[ani[chef.aniCnt/2]], true);
		DrawGraph(0, 263, chef.bg2, true);

	}

	void Fin()
	{
		DeleteGraph(chef.bg1);
		DeleteGraph(sub.food[0]);
		DeleteGraph(sub.food[1]);
		DeleteGraph(sub.stf);
		for (int i = 0; i < 3; i++) {
			DeleteGraph(chef.chef[i]);
		}
		DeleteGraph(chef.bg2);
	}

	void Sub_Animation()
	{
		
		if (sub.x >= 960)		//画面から消えたら位置を初期化
		{
			sub.x = -175;
			sub.flag = false;
		}
		if (staff.current >= 18461.54 && staff.current <= 19000.54) //18461.54（３分の１の区切りいい部分）
		{
			sub.foodNum = 0;
			sub.flag = true;
		}

		if (staff.current >= 47076.92 && staff.current <= 48876.92)  //47076.92（３分の２の区切りいい部分）
		{
			sub.foodNum = 1;
			sub.flag = true;
		}

		if (sub.flag == true) {	
			sub.x += 2;
			if (sub.state == down && sub.anime == true) {
				sub.y -= 1;
				++sub.aniCnt;
				if (sub.aniCnt >= 10) {
					sub.state = up;
					sub.anime = false;
					sub.aniCnt = 0;
				}
			}
			if (sub.state == up && sub.anime == true) {
				sub.y += 1;
				++sub.aniCnt;
				if (sub.aniCnt >= 10) {
					sub.state = down;
					sub.anime = false;
					sub.aniCnt = 0;
				}
			}
		}
	}
}