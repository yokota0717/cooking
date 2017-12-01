#include "Usingheaders.h"

static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	//ログ消し
	SetOutApplicationLogValidFlag(FALSE);
	//ウインドウタイトルを変更
	SetMainWindowText("CookingMaster");
	//画面サイズ変更
	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	//ウィンドウモード変更と初期化と裏画面設定
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);	
	
	auto manager = SceneManeger::GetInstance();

	//最初に映るシーン
	manager->PushScene(new Title);

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !manager->isEmpty())
	{
		Updata_Key();
		manager->GetCurrentScene()->Update();
		manager->GetCurrentScene()->Draw();
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}

    DxLib_End();
    return 0;
}