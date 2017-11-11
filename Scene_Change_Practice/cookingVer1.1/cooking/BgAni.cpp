#include "Usingheaders.h"

namespace BgAni {

	int background;
	int chef[2];
	int aniCnt;
	int check;
	bool Initialize()
	{
		check = LoadDivGraph("./Graph/chef.png", 2, 2, 1, 227, 220, chef);
		background = LoadGraph("./Graph/bg.png");
		aniCnt = 0;
			if (background == -1 || check == -1)
			{
				return false;
			}

		return true;
	}

	void Updata()
	{
		++aniCnt;
		if (aniCnt >= 60) {
			aniCnt = 0;
		}
	}

	void Draw()
	{
		DrawGraph(0, 0, background, true);
		DrawGraph(40, 27, chef[aniCnt/30], true);
	}

	void Fin()
	{
		DeleteGraph(background);
	
		for (int i = 0; i < 2; ++i)
		{
			DeleteGraph(chef[i]);
		}
	}
}