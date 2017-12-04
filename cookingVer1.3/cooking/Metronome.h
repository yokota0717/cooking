#pragma once
namespace Metronome {
	struct StaffAnimation {
		float BPM = 130;				//曲BPM
		float second = 60;			//1秒
		int singlfps = 1000/60;		//1フレーム分の時間[ms]

		int beat = 4;					//拍子
		float sibu = 1000 * (second / BPM);		//4分音符1個分の終了点
		int cnt = 1;
		bool flag = true;
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
