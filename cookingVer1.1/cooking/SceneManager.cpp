#include "DxLib.h"
#include "Task_Title.h"
#include "Input.h"
#include "Game.h"
#include "SceneManager.h"

SceneMgr::SceneMgr() :
	nextscene(Task_None)							//次のシーン管理変数
{
	scene = (BaseScene*) new Title(this);
}

//初期化
void SceneMgr::Initialize() {
	scene->Initialize();
}

//終了処理
void SceneMgr::Finalize()
{
	scene->Finalize();
}

//更新
void SceneMgr::Update() 
{
	if (nextscene != Task_None)						 //次のシーンがセットされていたら
	{    
		scene->Finalize();							 //現在のシーンの終了処理を実行
		delete scene;

		switch (nextscene)							 //シーンによって処理を分岐
		{       
		case Task_Title:					         //次の画面がタイトルなら
			scene = (BaseScene*) new Title(this);    //タイトル画面のインスタンスを生成する
			break;									 //以下略
		case Task_Game:
			scene = (BaseScene*) new Game(this);
			break;
		}
		nextscene = Task_None;						 //次のシーン情報をクリア
		scene->Initialize();						 //1度だけシーンを初期化
	}
	scene->Update();								 //シーンの更新
}

//描画
void SceneMgr::Draw()
{
	scene->Draw();									 //シーンの描画
}

// 引数NextSceneにシーンを変更する
void SceneMgr::ChangeScene(Scene NextScene) {
	nextscene = NextScene;    //次のシーンをセットする
}
