#include "Usingheaders.h"
//メインゲームシーン

bool Game::Initialize()
{
	//初期化ミスチェック
	if (!BgAni::Initialize() ||
		!Note::Initialize()  ||
		!Player::Initialize()||
		!Sound::Initialize())
	{
		return false;
	}
	return true;		
}
void Game::Update()
{
	Sound::PlayBGM();
	BgAni::Updata();
	Note::Updata();
	Player::Updata();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}

}
void Game::Draw()
{
	BgAni::Draw();
	Note::Draw();
	Player::Draw();

}
void Game::Finalize()
{
	BgAni::Fin();
	Sound::Fin();
	Note::Fin();
	Player::Fin();
    //↑の方が解放を意識できる
	//↓だと勝手に全部解放してくれる

	/*InitGraph();
	InitSoundMem();*/

}
