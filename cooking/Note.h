#pragma once
namespace Note {

	struct POS
	{			//���W
		float x;
		float y;
	};
	enum Type
	{			//�����̃^�C�v

		one,
		rest,
		mouse,

	}; 
	enum State 
	{
		come,
		cut,
		off,
	};
	struct Note 
	{
		float		 speed,
					  time;  //�x�W�G�Ȑ��g���Ƃ��Ɏg���Ăˁ�
		POS			   pos,   //���݂̍��W
					 start,  //�o���n�_
					   dir,  //�x�W�G�Ȑ��̕����_
					   end;  //�x�W�G�Ȑ��̏I�_�A���͓����蔻��̈�
		int			   Cnt,	//�t���[���J�E���g
				  animeCnt,	//�A�j���J�E���g	
			  picHandle[4];	//�摜
		bool        active;	
		State        state;
		Type          type;	//�����̎��

	};

	void Initialize();

	void Updata();

	void Draw();

	void Fin();
}
