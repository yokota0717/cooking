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
enum Hit
{
	Normal,
	hit,
	miss,
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
	int	   judge[100];		//判定時間
	int	      ID[100];		//画像とSEの情報
	int	  appear[100];		//出現時間
	int	      current;		//曲の再生場所
	//添え字
	int			j_cnt;		//判定数
	int        ID_cnt;		//次のIDに進める
	int         a_cnt;		//出現数
	
	int	        score;		//得点
	Hit	          hit;		//判定用
		
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

bool Note_Check_Good(int c, int j);
bool Note_Check_Cool(int c, int j);
bool Note_Check_Bad(int c, int j);