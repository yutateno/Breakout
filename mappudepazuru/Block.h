#pragma once

class Block {

private:

	const int block_width = 80;	//�u���b�N�̉���
	const int ball_size = 6;	//�{�[���̃T�C�Y
	const int block_height = 12;//�u���b�N�̏c��
	int block_x;				//�u���b�N�̂����W
	int block_y;				//�u���b�N�̂����W
	int r, g, b;				//�F
	int count;					//������艺���Ă���
	bool flag_remove;			//�{�[���ɓ������������(�P�Ȃ����

public:

	Block();										//�R���X�g���N�g
	Block(int block_x, int block_y);				//���W�w�肷��R���X�g���N�g
	~Block();										//�f�X�g���N�g
	void Block_Update();							//�X�V
	void Block_Draw();								//�`��
	bool flag_ballhit_up(int Ball_x, int Ball_y);	//��Ń{�[���ɓ��������t���b�O
	bool flag_ballhit_down(int Ball_x, int Ball_y);	//���Ń{�[���ɓ��������t���b�O
	bool flag_ballhit_left(int Ball_x, int Ball_y);	//���Ń{�[���ɓ��������t���b�O
	bool flag_ballhit_right(int Ball_x, int Ball_y);//�E�Ń{�[���ɓ��������t���b�O
};