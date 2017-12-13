#pragma once
namespace Player
{
	
	enum State {
		up,
		down,
		cut,
	};

	enum Dir {
		NON, //	èâä˙èÛë‘
		LEFT,
		RIGHT,
		TOP,
		BOTTOM,
	};

	struct Cock
	{
		int		        x,
				        y,
				        w,
			            h,
		 	      animCnt,
			picHandle[3];
		int e_pic;
		bool          flag;
		State	    state;
		Dir			   dir;
	};

	struct Effect
	{
		bool flag;
		int Cnt;
	};

	bool Initialize();

	void Update();

	void Draw();

	void Fin();

	void Effect_On();

	void  CutL_On();
	void  CutR_On();
	void  Set_Cut();

}
