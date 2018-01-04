#pragma once
enum TYPE
{

	appear,			//音符出現音0
	carrot,			//ニンジン1
	onion,			//タマネギ2
	broccoli,		//ブロッコリー3
	cabbage,		//キャベツ4
	tomato,			//トマト5
	potato,			//ジャガイモ6
	mouse,			//ネズミ7




	meat,			//肉8
	cuttingboard,	//まな板9
	simmer,			//煮る10
	grill,			//焼く11
	jump,			//ジャンプ12
	slash,			//切る13
	bell,			//入店音（ベル）14
	bell2,			//退勤音15

};


class Sound 
{
private:

	static constexpr int SENUM = 16;
	bool   flag;

public:

	TYPE se_type;
	int    SE[SENUM];
	int    BGM;
	bool Initialize();
	void SetBGM(const TCHAR *FileName);	//BGMとして使いたいファイルのパスを指定
	int  PlayBGM_BACK();				//BGMをバックグラウンド再生（ループなし）
	int  PlayBGM_LOOP();				//BGMをループ再生
	void InitBGM();						//現在格納されているBGMデータを解放し、再生フラグの再セット
	int  PlaySE(int);					//enum型でIDを指定、戻り値は0
	void Fin();							//全データ開放

};