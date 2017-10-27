#include "Input.h"
#include "Player.h"
#include "DxLib.h"

namespace Player {
	static const int
		SCREEN_WIDIH = 960,
		SCREEN_HEIGHT = 540;
	Cock cock;
	Cock check;	//あたり判定の可視化に用いる、不要になったら削除
	void Initialize()
	{
		cock.x = SCREEN_WIDIH / 2 - 50;
		cock.y = SCREEN_HEIGHT / 2 - 100;
		cock.w = 100;
		cock.h = 225;
		check.x = cock.x + cock.w + 100;
		check.y = cock.y + cock.h / 2;
		LoadDivGraph("./Graph/player.png", 2, 2, 1, 100, 225, cock.picHandle);
		cock.state = stand;
		cock.animCnt = 0;
	}

	void Updata()
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
			DrawGraph(cock.x, cock.y, cock.picHandle[0], true);
		}
		if (cock.state == cut) {
			DrawGraph(cock.x, cock.y, cock.picHandle[1], true);
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
		DrawCircle(check.x - cock.w - 50, check.y - 200, 50, GetColor(255, 0, 0), false);
		DrawCircle(check.x - cock.w - 50, check.y + 150, 50, GetColor(255, 0, 0), false);
	}

	void Fin()
	{
		for (int i = 0; i < num; ++i)
		{
			DeleteGraph(cock.picHandle[i]);
		}
	}
}
