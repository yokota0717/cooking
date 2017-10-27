#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Game.h"
#include "Note.h"
#include "Sound.h"

namespace Game {
	static const int
	SCREEN_WIDIH = 960,
	SCREEN_HEIGHT = 540;
	int back;
	
	void Initialize()
	{
		back = LoadGraph("./Graph/bg.png");
		Note::Initialize();
		Player::Initialize();
		Sound::Initialize();
	}
	void Updata()
	{
		//Sound::PlayBGM();
		Note::Updata();
		Player::Updata();
		
	}
	void Draw()
	{
		
		DrawGraph(0, 0, back, true);
		Note::Draw();
		Player::Draw();
	
	}
	void Fin()
	{
		Sound::Fin();
		Note::Fin();
		Player::Fin();
		DeleteGraph(back);
	}
}