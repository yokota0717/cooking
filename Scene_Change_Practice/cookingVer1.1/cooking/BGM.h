#pragma once
namespace BGM {
	struct Bgm {
		float BPM ;				//曲BPM
		float second ;			//1秒
		int singlfps ;		//1フレーム分の時間[ms]

		int beat ;					//拍子
		float sibu ;		//4分音符1個分の終了点
		int SE;
		int BGM;
		int cnt;
		bool flag;
		int current;

		int bg2;	//テーブルと床
		int chef[3];
		int chefY;	//コックさんのＹの値
		int mtr;
		bool anime; //アニメーションを始める時間を取る
		int aniCnt; //アニメーションが再生するフレイム
	};
	
	bool Initialize();

	void Updata();

	void Draw();

	void Fin();
}
