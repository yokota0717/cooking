#include "DxLib.h"
#include "title.h"
namespace Title {

	int titleGraph;

	void Initialize()
	{
		titleGraph = LoadGraph("./Graph/�^�C�g��.bmp");
	}
	void Updata()
	{

	}
	void Draw()
	{
		DrawGraph(0, 0, titleGraph,true);
	}
	void Fin()
	{
		DeleteGraph(titleGraph);
	}
}