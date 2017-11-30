#include "Usingheaders.h"
//メインゲームシーン
Fps fps;		//デバッグ用にFPSを表示
Sound sound;
Note note;
static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;
Sound GetSound()
{
	return sound;
}

bool Game::Initialize()
{

	//初期化ミスチェック
	if (
		!note.Initialize()   ||
		!Player::Initialize()||
		!sound.Initialize()  ||
		!note.LoadScore()    ||
		!Metronome::Initialize())
	{
		return false;
	}
	sound.PlayBGM();
	
	return true;		
}
void Game::Update()
{
	
	Metronome::Update();
	note.Update();
	Player::Update();
	fps.Update();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}
	fps.Wait();
}
void Game::Draw()
{
	Metronome::Draw();
	
	note.Draw();
	Player::Draw();
	fps.Draw();
}
void Game::Finalize()
{
	Metronome::Fin();
	
	sound.Fin();
	note.Fin();
	Player::Fin();
    //↑の方が解放を意識できる
	//↓だと勝手に全部解放してくれる

	/*InitGraph();
	InitSoundMem();*/
}
