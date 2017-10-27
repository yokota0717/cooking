#include "DxLib.h"
#include "Input.h"
#include "SceneManager.h"

static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ウインドウタイトルを変更
	SetMainWindowText("CookingMaster");
	//ウィンドウモード変更と初期化と裏画面設定
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	TitleInit();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();			//キー入力を有効にする
		ChangeScene();
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	InitGraph();
	InitSoundMem();
	DxLib_End();			// DXライブラリ終了処理
	return 0;
}