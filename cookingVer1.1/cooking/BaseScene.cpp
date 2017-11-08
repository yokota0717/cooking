#include "BaseScene.h"
#include "DxLib.h"

BaseScene::BaseScene(ISceneChanger* changer) :
	mImageHandle(0)
{
	mSceneChanger = changer;
}

void BaseScene::Finalize()
{
	InitGraph();
	InitSoundMem();

}

void BaseScene::Draw()
{
	
}