#pragma once

class Bar {

private:

	const int bar_y = 400;		//�o�[�̂����W�K��
	const int bar_speed = 15;	//�o�[�̑����K��
	const int bar_width = 50;	//�o�[�̉����K��
	const int bar_height = 10;	//�o�[�̍����K��
	const int ball_size = 6;	//�{�[���̃T�C�Y
	int bar_x;					//�o�[�̂����W

public:

	Bar();										//�R���X�g���N�g
	~Bar();										//�f�X�g���N�g
	void Bar_Update(int ball_y);				//�X�V
	void Bar_Draw();							//�`��
	bool flag_ballhit(int ball_X, int ball_Y);	//�{�[���̓�����t���b�O
};