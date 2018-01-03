#pragma once
namespace Metronome {
	enum State {
		up,
		down,
	};

	struct StaffAnimation {
		float BPM;				//曲BPM
		float second;			//1秒
		int singlfps;		//1フレーム分の時間[ms]

		int beat;					//拍子
		float sibu;		//4分音符1個分の終了点
		int cnt;
		bool flag;
		int current;

	};
	struct ChefAnimation {
		int bg1;    //キッチン
		int bg2;	//テーブルと床
		int chef[3];
		int chefY;	//コックさんのＹの値
		int mtr;
		bool anime; //アニメーションを始める時間を取る
		int aniCnt; //アニメーションが再生するフレイム
	};
	
	struct SubAnimation {
		bool flag;		//部下の表示フラッグ
		int x, y,		//部下のx,y値
			stf,		//部下の画像
			aniCnt,		//アニメーションカウント
			food[2],	//食べ物の画像
			foodNum;	//画像番号
		State state;	//上下アニメーションのため
		bool anime;		//
	};

	bool Initialize();

	void Update();

	void Draw();

	void Fin();
}
