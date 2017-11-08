#pragma once
typedef enum
{
	Task_Title,		//タイトル
	Task_Game,		//ゲーム画面


	Task_None,		//無し
	
} Scene;

//シーンを変更するためのインターフェイスクラス
class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(Scene NextScene) = 0;//指定シーンに変更する
};