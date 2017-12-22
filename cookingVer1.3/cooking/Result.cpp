#include "Usingheaders.h"

bool Result::Initialize()
{
	
	bghandle = LoadGraph("./Graph/リザルト.png");
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
	if (Score() >= 100)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "100点以上です");
	}
}

void Result::Finalize()
{
	InitGraph();
	//InitSoundMem();	//今のところ音がないので使わない
}