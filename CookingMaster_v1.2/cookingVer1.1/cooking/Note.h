#pragma once
namespace Note {

	struct POS
	{			//座標
		float x;
		float y;
	};
	enum Type
	{			//音符のタイプ

		one,	//単発
		rest,	//長押し(休符)
		mouse,	//ネズミ(下からくるよ)
	}; 
	enum State 
	{
		come,
		cut,
		off,
	};
	struct Note 
	{
		int			 just_Note[1000];	//音符の判定の情報
		int			 ID[1000];			//音符の画像とSEのID
		int			 note_appear[1000];	//音符の出現時間(SE鳴らしたいだけ)
		int			 current;
		int			 notenum;		//判定音符数
		int			 appeared;		//出現音符数
		int			 IDnum;			//画像とSEのデータのカウンタ
		float		 speed,
					  time;  //ベジエ曲線使うときに使ってね☆
		POS			   pos,   //現在の座標
					 start,  //出現地点
					   dir,  //ベジエ曲線の方向点
					   end;  //ベジエ曲線の終点、大抵は当たり判定領域
		int		  animeCnt,	//アニメカウント	
			  picHandle[4];	//画像
	
		
		State        state;
		Type          type;	//音符の種類

	};

	bool LoadScore();

	bool Initialize();

	//bool Note_Apper();

	void Update();

	void Draw();

	void Fin();
}
