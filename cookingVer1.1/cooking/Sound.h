#pragma once
namespace Sound {

	enum SETYPE
	{
		carrot,			//ニンジン
		onion,			//タマネギ
		broccoli,		//ブロッコリー
		cabbage,		//キャベツ
		tomato,			//トマト
		potato,			//ジャガイモ
		mouse,			//ネズミ
		meat,			//肉
		cuttingboard,	//まな板
		simmer,			//煮る
		grill,			//焼く
		jump,			//ジャンプ
		slash,			//切る
		bell,			//入店音（ベル）
		apper,			//音符出現音



	};

	void Initialize();

	void PlayBGM();

	int PlaySE(int);	//enum型でIDを指定、戻り値はIDに対応したSE

	void Fin();

}