#include "DxLib.h"
#include "title.h"
#include "Input.h"
#include "Game.h"
enum Scene
{
	//必要に応じて追加
	Task_Title,
	Task_Game,

};Scene scene;
void TitleInit()
{
	Title::Initialize();
}
//シーン管理
void ChangeScene()
{
	switch (scene)
	{
	case Task_Title:
		Title::Updata();
		Title::Draw();
		if (Key(KEY_INPUT_X) == 1)
		{
			Title::Fin();
			Game::Initialize();
			scene = Task_Game;
		}
		break;
	case Task_Game:
		Game::Updata();
		Game::Draw();
		if (Key(KEY_INPUT_X) == 1)
		{
			Game::Fin();
			Title::Initialize();
			scene = Task_Title;
		}
		break;
	}
}
