#include "Usingheaders.h"
#include "Game_OP.h"

bool OP::Initialize()
{
	α = 0;
	cook = LoadGraph("./Graph/stand.png");
	BG1 = LoadGraph("./Graph/bg.png");
	BG2 = LoadGraph("./Graph/bg2.png");
	chef = LoadGraph("./Graph/chef.png");

	if (cook == -1 || BG1 == -1 || BG2 == -1 || chef == -1)
	{
		return false;
	}

	return true;
}

void OP::Update()
{
	if(α <= 255)
	{
		++α;
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
		SceneManeger::GetInstance()->ChangeScene(new Game);
	}
	
}

void OP::Draw()
{

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, α);		//ブレンドモードαを設定
	DrawGraph(0, 0, BG1, true);
	DrawGraph(0, 263, BG2, true);
	DrawRectGraph(40, 27, 264, 0, 132, 243, chef,true, false);
	DrawRectRotaGraph(480, 330, 0, 0, 277, 524, 0.6,0,cook, true, false);
	
}

void OP::Finalize()
{
	InitGraph();
}