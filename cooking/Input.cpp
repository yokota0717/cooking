#include "DxLib.h"
#include "Input.h"

static int key[256];	//�L�[�̓��͏�Ԃ��i�[����

						//�L�[�̓��͏�Ԃ̍X�V
void Updata_Key()
{
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);	//���݂̃L�[�̏�Ԃ��i�[
	for (int i = 0; i < 256; ++i)
	{
		if (tmpKey[i] != 0)
		{
			++key[i];
		}
		else  //������Ă��Ȃ����
		{
			key[i] = 0;
		}
	}
}
//keycode�̃L�[�̓��͏�Ԃ��擾����
int Key(int keycode)
{
	return key[keycode];	//keycode�̓��͏�Ԃ�Ԃ�
}