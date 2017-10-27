#include "Sound.h"
#include "DxLib.h"
namespace Sound {

	SETYPE setype;
	int SE;
	int BGM;
	bool flag;

	void Initialize()
	{
		SE = LoadSoundMem("./Sound/slashing01.ogg");
		BGM = LoadSoundMem("./Sound/BPM140.wav");
		flag = true;
	}
	void PlayBGM()
	{
		if (flag == true)
		{
			PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
			flag = false;
		}
	}
	int PlaySE(int type)
	{
		switch (type)
		{
		case carrot:
			PlaySoundMem(SE, DX_PLAYTYPE_BACK);
			break;
		}
		return 0;
	}
	void Fin()
	{
		DeleteSoundMem(BGM);
	}
}
