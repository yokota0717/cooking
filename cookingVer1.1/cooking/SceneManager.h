#pragma once
#include "ISceneChanger.h"
#include "BaseScene.h"

class SceneMgr : public ISceneChanger, Task 
{

private:
	BaseScene* scene;    //シーン管理変数
	Scene nextscene;     //次のシーン管理変数

public:
	SceneMgr();
	void Initialize() override;	//初期化
	void Finalize()   override;	//終了処理
	void Update()     override;	//更新
	void Draw()       override;	//描画

						 // 引数 nextScene にシーンを変更する
	void ChangeScene(Scene NextScene) override;

};
