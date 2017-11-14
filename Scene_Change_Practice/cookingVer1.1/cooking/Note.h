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
		double			   Cnt;	//フレームカウント
		int		  animeCnt,	//アニメカウント	
			  picHandle[4];	//画像
		double BPM;									//テンポ
		double BGM_time;							//曲の時間
		double beat;								//拍
		double fourn_note;// = BPM / 60;			//4分音符
		double eight_note;
		double hit_time;// fourn_note * 2.0;		//実際に判定を取り始めるタイミング
		double Bar_end;// = fourn_note * beat;			//1小節の長さ(終端
		State        state;
		Type          type;	//音符の種類

	};

	bool Initialize();

	void Updata();

	void Draw();

	void Fin();
}
