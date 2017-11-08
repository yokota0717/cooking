#include "Input.h"
#include "Task_Title.h"
#include "DxLib.h"
#include "titlt_aaa.h"
static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;
Title::Title(ISceneChanger* changer) : BaseScene(changer)
{

}

//初期化
void Title::Initialize() 
{
	Title_G::Initialize();
}

//更新
void Title::Update() 
{
	if (Key(KEY_INPUT_X) == 1) //Xキーが押されていたら 
	{   
		mSceneChanger->ChangeScene(Task_Game);//シーンをメニューに変更
	}
}

//描画
void Title::Draw() 
{
	Title_G::Draw();
}

void Title::Finalize()
{
	BaseScene::Finalize();//親クラスの終了メソッドを呼ぶ
}