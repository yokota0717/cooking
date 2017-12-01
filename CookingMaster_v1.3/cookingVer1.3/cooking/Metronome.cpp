#include "Usingheaders.h"
#include <math.h>

namespace Metronome {
	StaffAnimation staff;

	

	bool Initialize() {
		staff.BPM = 130;									//曲BPM
		staff.second = 60;								//1秒
		staff.singlfps = 1000 / 60;						//1フレーム分の時間[ms]

		staff.beat = 4;									//拍子
		staff.sibu = 1000 * (staff.second / staff.BPM);		//4分音符1個分の終了点

		staff.cnt = 1;
		staff.flag = true;


		staff.chefY = 27;
		staff.anime = true;
		staff.aniCnt = 0;
		staff.mtr = LoadDivGraph("./Graph/chef.png", 3, 3, 1, 130, 247, staff.chef);
		staff.bg1 = LoadGraph("./Graph/bg.png");
		staff.bg2 = LoadGraph("./Graph/bg2.png");

		if (staff.mtr == -1 || staff.bg2 == -1)
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
			staff.anime = true;
			++staff.cnt;
		}

		if (staff.flag == false)
		{
			staff.sibu = 1000 * (staff.second / staff.BPM);
			staff.sibu *= staff.cnt;
			staff.flag = true;
		}
	}

	void Draw()
	{
		int ani[7] = { 2,2,1,1,0,1,2 }; //アニメーションにディレイをかけるために要素数を増やしている（実際は5こま）
		if (staff.anime == true) {
			staff.aniCnt++;
			if (staff.aniCnt < 5) {
				staff.chefY += 2;
			}
			else if (staff.aniCnt < 7) {
				staff.chefY -= 4;
			}
			else {
				staff.anime = false;
				staff.aniCnt = 0;
			}
		}
		
		DrawGraph(0, 0, staff.bg1, true);
		DrawGraph(40, staff.chefY, staff.chef[ani[staff.aniCnt]], true);
		DrawGraph(0, 263, staff.bg2, true);

	}

	void Fin()
	{
		DeleteGraph(staff.bg2);
		for (int i = 0; i < 3; i++) {
			DeleteGraph(staff.chef[i]);
		}
	}

}