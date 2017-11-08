#include "BaseScene.h"
#include "DxLib.h"

BaseScene::BaseScene(ISceneChanger* changer) :
	mImageHandle(0)
{
	mSceneChanger = changer;
}

void BaseScene::Finalize()	//シーン終了時に1度だけ実行される
{
	InitGraph();			//読み込んだすべての画像を解放
	InitSoundMem();			//読み込んだすべての音楽ファイルを解放
}

void BaseScene::Draw()
{
	
}