#include "DxLib.h"
#include < iostream >
#include "Breakout.h"

using namespace std;

//�R���X�g���N�g�K�������
Breakout::Breakout() {
	
}

Breakout::Breakout(int ball_speed, int block_num) {
	this->block_num = block_num;
	ball = new Ball(ball_speed);
	bar = new Bar();
	block_x = 0;
	block_y = 0;
	block.reserve(this->block_num);	//�T�C�Y�������Ă�̂Ō��m��
	for (num = 0; num < this->block_num; num++) {
		block.push_back(Block(block_x * block_weight, block_y * block_height));
		block_x++;
		if (block_x == 8) {
			block_y++;
			block_x = 0;
		}
	}
}

//�f�X�g���N�g
Breakout::~Breakout() {

	delete ball, bar;
}

//�X�V
void Breakout::Breakout_Update() {
	if (ball->get_y() >= 486) {	//�{�[���̔��a�𑫂��Ă�
		//���������Ȃ�
	}
	else {
		ball->Ball_Update();
		bar->Bar_Update(ball->get_x());
		if (bar->flag_ballhit(ball->get_x(), ball->get_y()) == 1) {
			ball->BarHit();
		}
		for (int i = 0; i < block_num; i++) {
			block[i].Block_Update();
			if (block[i].flag_ballhit_down(ball->get_x(), ball->get_y()) == 1) {
				ball->BlockHit_Down();
			}
			if (block[i].flag_ballhit_up(ball->get_x(), ball->get_y()) == 1) {
				ball->BlockHit_Up();
			}
			if (block[i].flag_ballhit_right(ball->get_x(), ball->get_y()) == 1) {
				ball->BlockHit_Right();
			}
				if (block[i].flag_ballhit_left(ball->get_x(), ball->get_y()) == 1) {
				ball->BlockHit_Left();
			}
		}
	}
}

//�`��
void Breakout::Breakout_Draw() {
	if (ball->get_y() >= 486) {	//�{�[���̔��a�𑫂��Ă�
		DrawFormatString(50, 200, GetColor(255, 255, 255), "�Q�[���I�[�o�[");
	}
	else {
		ball->Ball_Draw();
		bar->Bar_Draw();
		for (int i = 0; i < block_num; i++) {
			block[i].Block_Draw();
		}
	}
}