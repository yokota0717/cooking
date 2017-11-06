#include "DxLib.h"
#include "Input.h"
#include "Player.h"
#include "Game.h"
#include "Note.h"
#include "Sound.h"
#include "BgAni.h"

namespace Game {
	static const int
	SCREEN_WIDIH = 960,
	SCREEN_HEIGHT = 540;
	int back;
	
	void Initialize()
	{
		BgAni::Initialize();
		Note::Initialize();
		Player::Initialize();
		Sound::Initialize();
	}
	void Updata()
	{
		//Sound::PlayBGM();
		BgAni::Updata();
		Note::Updata();
		Player::Updata();
		
	}
	void Draw()
	{
		BgAni::Draw();
		Note::Draw();
		Player::Draw();
	
	}
	void Fin()
	{
		BgAni::Fin();
		Sound::Fin();
		Note::Fin();
		Player::Fin();
	}
}