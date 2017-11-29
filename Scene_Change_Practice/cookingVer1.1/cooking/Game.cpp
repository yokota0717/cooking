#include "Usingheaders.h"
//メインゲームシーン
Fps fps;		//デバッグ用にFPSを表示
Sound sound;

Sound GetSound()
{
	return sound;
}

bool Game::Initialize()
{

	//初期化ミスチェック
	if (!BgAni::Initialize() ||
		!Note::Initialize()  ||
		!Player::Initialize()||
		!sound.Initialize()  ||
		!Note::LoadScore()   ||
		!BGM::Initialize())
	{
		return false;
	}
	sound.PlayBGM();
	
	return true;		
}
void Game::Update()
{
	BgAni::Updata();
	BGM::Updata();
	Note::Updata();
	Player::Updata();
	fps.Update();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}
	fps.Wait();
}
void Game::Draw()
{
	BGM::Draw();
	BgAni::Draw();
	Note::Draw();
	Player::Draw();
	fps.Draw();
}
void Game::Finalize()
{
	BGM::Fin();
	BgAni::Fin();
	sound.Fin();
	Note::Fin();
	Player::Fin();
    //↑の方が解放を意識できる
	//↓だと勝手に全部解放してくれる

	/*InitGraph();
	InitSoundMem();*/
}
