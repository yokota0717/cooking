#include "Usingheaders.h"

bool Result::Initialize()
{
	POS test(0, 0);
	POS lhs(0, 0);
	POS rhs(0, 0);
	test = lhs + rhs;
	bghandle = LoadGraph("./Graph/ƒŠƒUƒ‹ƒg.png");
	if (bghandle == -1)
	{
		return false;
	}
	return true;
}

void Result::Update()
{
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
	}
}

void Result::Draw()
{
	DrawGraph(0, 0, bghandle, true);
}

void Result::Finalize()
{
	InitGraph();
	//InitSoundMem();	//¡‚Ì‚Æ‚±‚ë‰¹‚ª‚È‚¢‚Ì‚Åg‚í‚È‚¢
}