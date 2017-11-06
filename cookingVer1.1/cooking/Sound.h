#pragma once
namespace Sound {

	enum SETYPE
	{
		carrot,
	};

	void Initialize();

	void PlayBGM();

	int PlaySE(int);	//enum‚ÅID‚ğw’èA–ß‚è’l‚ÍID‚É‘Î‰‚µ‚½SE

	void Fin();

}