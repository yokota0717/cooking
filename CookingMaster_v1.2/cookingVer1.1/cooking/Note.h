#pragma once
struct POS
{			//座標
	float x;
	float y;
};
enum N_Type
{			//音符のタイプ

	N_one,	//単発
	N_rest,	//長押し(休符)
	N_mouse,	//ネズミ(下からくるよ)
}; 
enum State 
{
	come,
	cut,
	off,
};
struct Move		//音符の動き（移動とアニメーション）
{
	POS		     pos,
			   start,
			     dir,
		         end;
	State	   state;
	N_Type note_type;
	int			time;
	float      speed;
	int	    animeCnt;
	int picHandle[4];

};
struct Data		//音符の判定などの情報
{
	int    judge[100],		//判定時間
		      ID[100],		//画像とSEの情報
		  appear[100],		//出現時間
		       current,		//曲の再生場所
				//添え字
		         j_cnt,		//判定数
		  	    ID_cnt,		//次のIDに進める
		         a_cnt;		//出現数
		
		
};
class Note
{
public:
	Data data;
	Move move;

	bool LoadScore();

	bool Initialize();

	void Update();

	void Draw();

	void Fin();
};

