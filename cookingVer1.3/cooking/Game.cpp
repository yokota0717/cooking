#include "Usingheaders.h"
//メインゲームシーン
Fps fps;		//デバッグ用にFPSを表示
Sound sound;
Note note[100];
File file;
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
		!Player::Initialize() ||
		!sound.Initialize() ||
		!file.LoadScore() ||
		!Metronome::Initialize())
	{
		return false;
	}
	for (int i = 0; i < 100; ++i)
	{
		note[i].SetScore(i, note[i], file);
	}
	//note[]のInitialze()の成否チェックは別に行う
	bool noteInitCheck[100] = {};
	for (int i = 0; i < 100; ++i) 
	{ 
		noteInitCheck[i] = note[i].Initialize();
		if (!noteInitCheck[i]) return false;
	}
	
	
	sound.PlayBGM();
	
	return true;		
}
void Game::Update()
{
	
	Metronome::Update();
	for (int i = 0; i < 100; ++i)
	{
		note[i].Update();
	}
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
	
	for (int i = 0; i < 100; ++i)
	{
		note[i].Draw();
	}
	Player::Draw();
	fps.Draw();
}
void Game::Finalize()
{
	Metronome::Fin();
	
	sound.Fin();
	for (int i = 0; i < 100; ++i) 
	{
		note[i].Fin();
	}
	Player::Fin();
    //↑の方が解放を意識できる
	//↓だと勝手に全部解放してくれる

	/*InitGraph();
	InitSoundMem();*/
}
