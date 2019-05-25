#pragma once
#include "Ball.h"
#include "Bar.h"
#include "Block.h"
#include <vector>

using namespace std;

class Breakout {
private:
	const int block_weight = 80;//�u���b�N�̂����W�̒�
	const int block_height = 12;//�u���b�N�̂����W�̒���
	int block_x;				//�u���b�N��x
	int block_y;				//�u���b�N��y
	int block_num;				//�u���b�N�̐�
	int num;
	Ball *ball;					//�{�[��
	Bar *bar;					//�o�[
	vector<Block> block;		//vector�͌�����new delete���Ă�炵������|�C���^����Ȃ�

public:

	Breakout();								//�R���X�g���N�g
	Breakout(int ball_speed, int block_n);	//�{�[���̃X�s�[�h�ƃu���b�N�̐����w��ł���R���X�g���N�g
	~Breakout();							//�f�X�g���N�g
	void Breakout_Update();					//�X�V
	void Breakout_Draw();					//�`��
};