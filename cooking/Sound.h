#pragma once
namespace Sound {

	enum SETYPE
	{
		carrot,
	};

	void Initialize();

	void PlayBGM();

	int PlaySE(int);	//enum��ID���w��A�߂�l��ID�ɑΉ�����SE

	void Fin();

}