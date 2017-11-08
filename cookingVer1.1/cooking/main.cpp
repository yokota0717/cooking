#include "DxLib.h"
#include "Input.h"
#include "SceneManager.h"

static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ログ消し
	SetOutApplicationLogValidFlag(FALSE);
	//ウインドウタイトルを変更
	SetMainWindowText("CookingMaster");
	//ウィンドウモード変更と初期化と裏画面設定
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	SceneMgr sceneMgr;
	sceneMgr.Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();			//キー入力を有効にする
		sceneMgr.Update();  //更新
		sceneMgr.Draw();    //描画
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}

	sceneMgr.Finalize();
	DxLib_End();			// DXライブラリ終了処理
	return 0;
}