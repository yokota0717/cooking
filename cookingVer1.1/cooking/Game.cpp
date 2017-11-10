#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Game.h"
#include "Note.h"
#include "Sound.h"
#include "BgAni.h"

static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;
Game::Game(ISceneChanger* changer) : BaseScene(changer) 
{
}

//初期化
void Game::Initialize() {
	BgAni::Initialize();
	Note::Initialize();
	Player::Initialize();
	Sound::Initialize();
}

//更新
void Game::Update() {
	if (Key(KEY_INPUT_X) == 1) //Xキーが押されていたら
	{ 
		mSceneChanger->ChangeScene(Task_Title);//シーンをタイトルに変更
	}
	//Sound::PlayBGM();
	BgAni::Update();
	Note::Update();
	Player::Update();
}

//描画
void Game::Draw()
{
	BaseScene::Draw();//親クラスの描画メソッドを呼ぶ
	BgAni::Draw();
	Note::Draw();
	Player::Draw();
}

//終了
void Game::Finalize()
{
	BaseScene::Finalize();//親クラスの終了メソッドを呼ぶ
}
