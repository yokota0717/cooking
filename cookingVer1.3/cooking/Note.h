#pragma once
constexpr int noteMax = 120;
extern const int
quarterNote,		//四分音符の長さ(ms)
halfNote,			//二分音符の長さ(ms)
dottedHalfNote;


struct POS
{			//座標
	float x;
	float y;
	POS(){}
	POS(float x, float y) :x(x), y(y) {}
	POS operator + (const POS& p) const {
		return POS({ x + p.x, y + p.y });
	}
	POS operator - (const POS& p) const {
		return POS({ x - p.x, y - p.y });
	}
	POS &operator += (const POS& p) {
		x += p.x;
		y += p.y;
		return (*this);
	}
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
enum Direction {	//出現位置の方向
	LEFT,
	RIGHT,
	BOTTOM,
};
struct BezierCurve {
	POS			bez;
	float		time;
	BezierCurve():
		bez({ 0,0 }), time(0) {}
	~BezierCurve() {}
	void BezTimeUpdate(N_Type nt, int current, int appear) {
		time = float(current - appear) / ((nt == N_one) ? (float)quarterNote : (float)halfNote);
	}
	POS MoveBezier2(POS start,POS dir,POS end){
		bez.x = (1 - time)*(1 - time)*start.x + 2 * (1 - time)*time*dir.x + time*time*end.x;
		bez.y = (1 - time)*(1 - time)*start.y + 2 * (1 - time)*time*dir.y + time*time*end.y;

		return bez;
	}
};
struct Move		//音符の動き（移動とアニメーション）
{
	POS		     pos,	//現在座標
			   start,	//出現位置
			     dir,	//方向点
		         end;	//判定座標
	State	   state;	//生死(主に画像の変化で使う)
	N_Type note_type;	//二分、四分
	float      speed;	//移動スピード、二分か四分かで決まる
	int	    animeCnt;	//アニメーション用カウンタ
	int pic_carrot[4],	//画像ハンドル
	   pic_cabbage[4],
		pic_potato[4],
		pic_tomato[4],
	  pic_broccoli[4],
		 pic_mouse[4],
		 pic_onion[4];



};
struct Data		//音符の判定などの情報
{
	int			judge;		//判定時間 ファイルから読み込む
	int			   ID;		//画像とSEの情報	ファイルから読み込む
	Direction	   d;		//左右どっちから来るか　ファイルから読み込む
	int		   appear;		//出現時間	judgeから算出
	int	      current;		//曲の再生場所
	////添え字
	//int			j_cnt;		//判定数
	//int        ID_cnt;		//次のIDに進める
	//int         a_cnt;		//出現数
	Hit	          hit;		//判定用
	
	
		
};
struct File {		//あほっぽい構造体。
	//一時保管用変数
	int judge[noteMax] = {};
	int id[noteMax] = {};
	int dir[noteMax] = {};

	bool LoadScore();	//ファイルの読み込み
};
class Note
{
	 int	imageSizeX = 100,
			imageSizeY = 100;
	 bool	appearSEplayed;
public:
	Data data;
	Move move;
	BezierCurve bez;
	bool start;
	//Note(){}
	void SetScore(int id, Note& note, const File& file);	//ファイルから読んだデータをセットする
	void SetN_Type(Note& note);			//N_Typeを決める
	void SetAppearTime(Note& note);		//出現タイミングを算出
	void SetSpeed(Note& note);			//移動速度を決める
	void SetBezierData(Note& note);		//start,dir,endを決める
	
	bool Initialize();

	void Update();

	void Draw();

	void Fin();
};

inline bool Note_Check_Good(int c, int j);
inline bool Note_Check_Cool(int c, int j);
inline bool Note_Check_Bad(int c, int j);
inline bool Auto(int c, int j);
inline int& Score(int s = 0);
