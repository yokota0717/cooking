#include "Usingheaders.h"
#include <math.h>

namespace BGM {
	Bgm bgm;

	

	bool Initialize() {
		bgm.BPM = 130;									//曲BPM
		bgm.second = 60;								//1秒
		bgm.singlfps = 1000 / 60;						//1フレーム分の時間[ms]

		bgm.beat = 4;									//拍子
		bgm.sibu = 1000 * (bgm.second / bgm.BPM);		//4分音符1個分の終了点

		bgm.cnt = 1;
		bgm.flag = true;


		bgm.chefY = 27;
		bgm.anime = false;
		bgm.aniCnt = 0;
		bgm.mtr = LoadDivGraph("./Graph/chef.png", 3, 3, 1, 130, 247, bgm.chef);
		bgm.bg2 = LoadGraph("./Graph/bg2.png");

		if (bgm.mtr == -1 || bgm.bg2 == -1)
		{
			return false;
		}

		return true;
	}

	void Updata()
	{
		bgm.current = GetSoundCurrentTime(bgm.BGM);
		if (bgm.current >= bgm.sibu && bgm.flag == true)
		{
			bgm.flag = false;
			++bgm.cnt;
		}

		if (bgm.flag == false)
		{
			bgm.sibu = 1000 * (bgm.second / bgm.BPM);
			bgm.sibu *= bgm.cnt;
			bgm.flag = true;
		}
	}

	void Draw()
	{
		int ani[7] = { 2,2,1,1,0,1,2 }; //アニメーションにディレイをかけるために要素数を増やしている（実際は5こま）
		if (bgm.anime == true) {
			bgm.aniCnt++;
			if (bgm.aniCnt < 5) {
				bgm.chefY += 2;
			}
			else if (bgm.aniCnt < 7) {
				bgm.chefY -= 4;
			}
			else {
				bgm.anime = false;
				bgm.aniCnt = 0;
			}
		}
		DrawGraph(40, bgm.chefY, bgm.chef[ani[bgm.aniCnt]], true);
		DrawGraph(0, 263, bgm.bg2, true);

	}

	void Fin()
	{
		DeleteGraph(bgm.bg2);
		for (int i = 0; i < 3; i++) {
			DeleteGraph(bgm.chef[i]);
		}
	}

	void Play(int &SE)
	{
		PlaySoundMem(SE, DX_PLAYTYPE_BACK);

		bgm.anime = true;
	}
}