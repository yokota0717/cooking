#include "Usingheaders.h"
 
bool Sound::Initialize()
{
	
	SE[appear] = LoadSoundMem("./Sound/出現.ogg");
	SE[carrot]  = LoadSoundMem("./Sound/bell.ogg");
	SE[cabbage] = LoadSoundMem("./Sound/キャベツ.ogg");
	SE[grill]   = LoadSoundMem("./Sound/肉を焼く.ogg");
	BGM = LoadSoundMem("./Sound/未完成.wav");


	flag = true;
	
	for (int i = 0; i < SENUM; ++i)
	{
		if (SE[i] == -1 || BGM == -1)
		{
			return false;
		}
	}
	return true;
}
int Sound::PlayBGM()
{
	if (flag == true)
	{
		ChangeVolumeSoundMem(/*255 * 80 / 100*/100, BGM);
		PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
		flag = false;
	}
	return BGM;
}
int Sound::PlaySE(int type)
{
	switch (type)
	{

	case carrot:      PlaySoundMem(SE[carrot],		 DX_PLAYTYPE_BACK);	break;
	case onion:       PlaySoundMem(SE[onion],		 DX_PLAYTYPE_BACK);	break;
	case broccoli:    PlaySoundMem(SE[broccoli],	 DX_PLAYTYPE_BACK);	break;
	case cabbage:     PlaySoundMem(SE[cabbage],		 DX_PLAYTYPE_BACK);	break;
	case tomato:      PlaySoundMem(SE[tomato],		 DX_PLAYTYPE_BACK);	break;
	case potato:	  PlaySoundMem(SE[potato],		 DX_PLAYTYPE_BACK);	break;
	case mouse:       PlaySoundMem(SE[mouse],		 DX_PLAYTYPE_BACK);	break;
	case meat:        PlaySoundMem(SE[meat],		 DX_PLAYTYPE_BACK);	break;
	case cuttingboard:PlaySoundMem(SE[cuttingboard], DX_PLAYTYPE_BACK);	break;
	case simmer:      PlaySoundMem(SE[simmer],		 DX_PLAYTYPE_BACK);	break;
	case grill:		  PlaySoundMem(SE[grill],		 DX_PLAYTYPE_BACK);	break;
	case jump:		  PlaySoundMem(SE[jump],		 DX_PLAYTYPE_BACK);	break;
	case slash:		  PlaySoundMem(SE[slash],		 DX_PLAYTYPE_BACK);	break;
	case bell:		  PlaySoundMem(SE[bell],		 DX_PLAYTYPE_BACK);	break;
	case appear:	  PlaySoundMem(SE[appear],		 DX_PLAYTYPE_BACK);	break;
					  
	}				  
	return 0;		  
}					  
void Sound::Fin()	  
{					  
	for (int i = 0; i < SENUM; ++i)
	{
		DeleteSoundMem(SE[i]);
	}
	DeleteSoundMem(BGM);

}