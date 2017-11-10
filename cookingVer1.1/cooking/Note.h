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
		float		 speed,
					  time;  //ベジエ曲線使うときに使ってね☆
		POS			   pos,   //現在の座標
					 start,  //出現地点
					   dir,  //ベジエ曲線の方向点
					   end;  //ベジエ曲線の終点、大抵は当たり判定領域
		int			   Cnt,	//フレームカウント
				  animeCnt,	//アニメカウント	
			  picHandle[4];	//画像
		bool        active;	
		State        state;
		Type          type;	//音符の種類

	};

	void Initialize();

	void Update();

	void Draw();

	void Fin();
}
