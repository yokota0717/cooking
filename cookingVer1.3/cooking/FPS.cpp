#include "Usingheaders.h"
#if _DEBUG
Fps::Fps():
mStartTime(0),
mCount(0),          //カウンタ
mFps(0)
{}

bool Fps::Update()
{
	//1フレーム目なら時刻を記憶
	if (mCount == 0)
	{
		mStartTime = GetNowCount();
	}
	//60フレーム目なら平均を計算する
	if (mCount == N)
	{
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	++mCount;
	return true;
}

void Fps::Draw()
{
	DrawFormatString(0, 520, GetColor(0, 0, 0), "%.1f", mFps);
}

void Fps::Wait()
{
	int tookTime = GetNowCount() - mStartTime;		//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0)
	{
		Sleep(waitTime);							//待機
	}

}
#endif