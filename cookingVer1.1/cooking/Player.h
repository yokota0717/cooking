#pragma once
namespace Player
{
	const int num = 35;
	enum State {
		stand,
		cut,
	};

	struct Cock
	{
		int		        x,
				        y,
				        w,
			            h,
		 	      animCnt,
			picHandle[num];
		State	    state;
	};

	void Initialize();

	void Updata();

	void Draw();

	void Fin();

}
