#pragma once

class Ball {

private:

	const int ball_size = 6;//�{�[���̑傫��
	int ball_x;				//�{�[���̂����W
	int ball_y;				//�{�[���̂����W
	bool WHF_x;				//�E�ǂɓ�������(WallHitFlag
	bool WHF_y;				//���ǂɓ�������(WallHitFlag
	int ball_speed;			//�{�[���̑��x

public:

	Ball();					//�R���X�g���N�g
	Ball(int ball_speed);	//�{�[���̑��x�ς����R���X�g���N�g
	~Ball();				//�f�X�g���N�g
	void BarHit();			//�o�[�ɓ�����
	void BlockHit_Up();		//�u���b�N�̏�ɓ�����
	void BlockHit_Down();	//�u���b�N�̉��ɓ�����
	void BlockHit_Left();	//�u���b�N�̍��ɓ�����
	void BlockHit_Right();	//�u���b�N�̉E�ɓ�����
	void Ball_Draw();		//�`��
	void Ball_Update();		//�X�V
	int get_x();			//�{�[���̂����W�擾
	int get_y();			//�{�[���̂����W�擾
};