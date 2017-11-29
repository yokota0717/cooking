#include "Usingheaders.h"

namespace Player {
	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	Cock cock;
	Cock check;	//あたり判定の可視化に用いる、不要になったら削除
	bool Initialize()
	{
		cock.x = SCREEN_WIDIH/2;
		cock.y = SCREEN_WIDIH/4 + 10;
		cock.w = 512;
		cock.h = 512;
		check.x = 630;
		check.y = 280;
		cock.picHandle[0] = LoadGraph("./Graph/512.png");
		//LoadDivGraph("./Graph/player.png", 2, 2, 1, 100, 225, cock.picHandle);
		cock.state = stand;
		cock.animCnt = 0;
		if (cock.picHandle[0] == -1)
		{
			return false;
		}
		return true;
	}

	void Update()
	{
		if (Key(KEY_INPUT_RIGHT) >= 1)
		{
			cock.x += 5;
		}
		if (Key(KEY_INPUT_LEFT) >= 1)
		{
			cock.x -= 5;
		}
		if (Key(KEY_INPUT_A) == 1)
		{
			cock.state = cut;
		}
	}

	void Draw()
	{
		if (cock.state == stand) {
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, cock.picHandle[0], true);
		}
		if (cock.state == cut) {
			DrawRotaGraph(int(cock.x), int(cock.y), 0.6, 0.0, cock.picHandle[1], true);
			++cock.animCnt;
			if (cock.animCnt >= 20) {
				cock.state = stand;
				cock.animCnt = 0;
			}
		}

		//仮のキャラ

		//あたり判定の可視化
		DrawCircle(check.x, check.y, 50, GetColor(255, 0, 0), false);
		DrawCircle(check.x / 2, check.y, 50, GetColor(255, 0, 0), false);
		DrawCircle(check.x - 155, check.y - 200, 50, GetColor(255, 0, 0), false);
		DrawCircle(check.x - 155, check.y + 150, 50, GetColor(255, 0, 0), false);
	}

	void Fin()
	{
		for (int i = 0; i < num; ++i)
		{
			DeleteGraph(cock.picHandle[i]);
		}
	}
}
