#include "Usingheaders.h"
#include "Game_OP.h"
//メインゲームシーン
#if _DEBUG
Fps fps;		//デバッグ用にFPSを表示
#endif
Sound sound;
Note note[noteMax];
File file;
extern const int
SCREEN_WIDIH,
SCREEN_HEIGHT;



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
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].SetScore(i, note[i], file);
	}
	//note[]のInitialze()の成否チェックは別に行う
	bool noteInitCheck[noteMax] = {};
	for (int i = 0; i < noteMax; ++i)
	{ 
		noteInitCheck[i] = note[i].Initialize();
		if (!noteInitCheck[i]) return false;
	}
	
	
	sound.PlayBGM_BACK();
	
	return true;		
}
void Game::Update()
{
	
	Metronome::Update();
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].Update();
	}
	Player::Update();
#if _DEBUG
	fps.Update();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Result);
	}
	fps.Wait();
#endif
}
void Game::Draw()
{
	Metronome::Draw();
	Player::Draw();
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].Draw();
	}
#if _DEBUG
	DrawFormatString(0, 0, GetColor(255, 0, 0),"得点：%d", Score());
	
	fps.Draw();
#endif
	if (GetSoundCurrentTime(sound.BGM) >= GetSoundTotalTime(sound.BGM) - 100)	//曲が終わったらリザルトへ
	{
		SceneManeger::GetInstance()->ChangeScene(new Result);
	}
}
void Game::Finalize()
{
	Metronome::Fin();
	
	sound.Fin();
	for (int i = 0; i < noteMax; ++i)
	{
		note[i].Fin();
	}
	Player::Fin();
    //↑の方が解放を意識できる
	//↓だと勝手に全部解放してくれる

	/*InitGraph();
	InitSoundMem();*/
}
