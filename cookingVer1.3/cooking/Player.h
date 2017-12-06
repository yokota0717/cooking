#pragma once
namespace Player
{
	
	enum State {
		up,
		down,
		cut,
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
	};

	bool Initialize();

	void Update();

	void Draw();

	void Fin();

}
