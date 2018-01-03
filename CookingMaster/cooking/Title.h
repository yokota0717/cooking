#pragma once

class Title : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;

	int α;		//透過率
	bool flag;	//フェードアウトフラグ
	struct POS
	{
		void SetPOS(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
		float x, y;
	};
	enum SELECT
	{
		Start,
		End
	};
	struct Cursor
	{
		POS pos;
		SELECT select;
		int handle;
	};
	Cursor cursor;			//カーソル
	int bgHandle;			//背景ハンドル
	struct Logo
	{
		POS pos;
		int handle;		
	};
	Logo logo;				//タイトルロゴ
	struct Startbutton
	{
		POS pos;
		int handle;
	};
	Startbutton s_button;	//スタートボタン
	struct Endbutton
	{
		POS pos;
		int handle;
	};
	Endbutton e_button;		//エンドボタン
};

