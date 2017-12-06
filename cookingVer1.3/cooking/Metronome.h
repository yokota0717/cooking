#pragma once
namespace Metronome {
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
	
	bool Initialize();

	void Update();

	void Draw();

	void Fin();
}
