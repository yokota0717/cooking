#include "DxLib.h"
#include "Input.h"
#include "SceneManager.h"

static const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//�E�C���h�E�^�C�g����ύX
	SetMainWindowText("CookingMaster");
	//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	TitleInit();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();			//�L�[���͂�L���ɂ���
		ChangeScene();
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	InitGraph();
	InitSoundMem();
	DxLib_End();			// DX���C�u�����I������
	return 0;
}