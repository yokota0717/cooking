#include "Usingheaders.h"

bool Result::Initialize()
{
	flag = false;
	bghandle = LoadGraph("./Graph/リザルト.png");
	sound.SetBGM("./Sound/肉を焼く.ogg");
	if (bghandle == -1)
	{
		return false;
	}
	return true;
}

void Result::Update()
{
	sound.PlayBGM_BACK();
	if (Key(KEY_INPUT_X) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Title);
		Score() = 0;
	}
}

void Result::Draw()
{
	DrawGraph(0, 0, bghandle, true);
	if (Score() >= 100 && Score() < 200)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "100点以上です");
	}
	if (Score() >= 200)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "200点以上です");
	}
	if (Score() < 100)
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "100点未満ですm9(^Д^)ﾌﾟｷﾞｬｰ");
	}
}

void Result::Finalize()
{
	InitGraph();
	InitSoundMem();
}