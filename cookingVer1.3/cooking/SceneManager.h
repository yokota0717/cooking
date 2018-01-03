#pragma once

//シーン管理部クラス

class SceneManeger
{
protected:
	static SceneManeger* instance;
	std::stack<Scene*> scenes;
private:
	static void DestroyThis()
	{
		delete instance;		//シーンのメモリを解放
	}
public:
	explicit SceneManeger() {}
	virtual ~SceneManeger() {}

	static SceneManeger* GetInstance()			
	{
		if (!instance)
		{
			instance = new SceneManeger();		//インスタンスが空なら新しいシーンを登録
			atexit(DestroyThis);				//プログラムが終了するときに実行される
		}
		return instance;
	}
		
	//シーンの追加
	//引数は呼び出したいシーンのポインタ
	//メインループ前に呼び出すか、ChangeSceneで指定したシーンを追加する
	//シーンの初期化が正しく行われているならtrue
	bool PushScene(Scene* s_)
	{
		if (s_ && !s_->Initialize())	
		{
			return false;
		}
		scenes.push(s_);		//新しいシーンを追加
		return true;
	}

	//シーンの削除
	//ChangeSceneで次のシーンに移行するときに行われる
	//削除に成功したらtrue
	bool PullScene()
	{
		if (scenes.empty())
		{
			return false;		//シーンがなければfalse
		}
		auto s = scenes.top();	//前のシーンを参照
		s->Finalize();			//前のシーンの終了処理
		delete s;				//前のシーン分のメモリの開放
		return true;
	}

	//シーンの切り替え
	//引数にシーン名をnewで指定する
	//PullSceneとPushSceneが行われる
	void ChangeScene(Scene* s_)
	{
		PullScene();
		PushScene(s_);
	}

	//現在映しているシーンを参照する
	//メインループに書くべき処理
	//主に更新処理、描画処理を参照する
	Scene* GetCurrentScene() const
	{
		return scenes.top();
	}

	//現在再生するシーンがスタックの中に残っているか調べる
	//ループの条件に追加する
	//
	bool isEmpty()
	{
		return scenes.empty();		//要素数（シーン）が空かどうか調べる
	}

};