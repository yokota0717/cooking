#include "DxLib.h"
#include "titlt_aaa.h"
namespace TT
{
	int pic;
	void Initialize()
	{
		
		pic = LoadGraph("./Graph/ƒ^ƒCƒgƒ‹.bmp");
		
	}
	void Draw()
	{
		DrawGraph(0, 0, pic, true);
	}
}