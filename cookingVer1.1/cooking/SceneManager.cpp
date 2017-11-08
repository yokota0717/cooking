#include "DxLib.h"
#include "Task_Title.h"
#include "Input.h"
#include "Game.h"
#include "SceneManager.h"

SceneMgr::SceneMgr() :
	mNextScene(Task_None) //次のシーン管理変数
{
	mScene = (BaseScene*) new Title(this);
}

//初期化
void SceneMgr::Initialize() {
	mScene->Initialize();
}

//終了処理
void SceneMgr::Finalize()
{
	mScene->Finalize();
}

//更新
void SceneMgr::Update() {
	if (mNextScene != Task_None)				     //次のシーンがセットされていたら
	{    
		mScene->Finalize();							 //現在のシーンの終了処理を実行
		delete mScene;
		switch (mNextScene)							 //シーンによって処理を分岐
		{       
		case Task_Title:					         //次の画面がタイトルなら
			mScene = (BaseScene*) new Title(this);   //タイトル画面のインスタンスを生成する
			break;									 //以下略
		case Task_Game:
			mScene = (BaseScene*) new Game(this);
			break;
		}
		mNextScene = Task_None;						 //次のシーン情報をクリア
		mScene->Initialize();						 //シーンを初期化
	}

	mScene->Update();								 //シーンの更新
}

//描画
void SceneMgr::Draw() {
	mScene->Draw(); //シーンの描画
}

// 引数 nextScene にシーンを変更する
void SceneMgr::ChangeScene(Scene NextScene) {
	mNextScene = NextScene;    //次のシーンをセットする
}
