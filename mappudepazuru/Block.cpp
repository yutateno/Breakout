#include "DxLib.h"
#include <iostream>
#include "Block.h"

using namespace std;

//�R���X�g���N�g
Block::Block() {
	block_x = 0;
	block_y = 0;
	r = 125, g = 125, b = 125;
	flag_remove = 0;
}

//�u���b�N�̈ʒu�������Ɏ�����R���X�g���N�g
Block::Block(int block_x, int block_y) {
	this->block_x = block_x;
	this->block_y = block_y;
	r = GetRand(254) + 1, g = GetRand(254) + 1, b = GetRand(254) + 1;
	flag_remove = 0;
}

//�f�X�g���N�g
Block::~Block() {

}


//�X�V�i����Ȃ�
void Block::Block_Update() {
	count++;
	if (count % 10 == 0 && count != 0) {
		block_y += (block_height / 3);
	}
	if (block_y >= 480) {
		block_y = 0;
	}
}

//�`��
void Block::Block_Draw() {
	//��ʂɑ��݂��Ă���
	if (flag_remove == 0) {
		DrawBox(block_x, block_y, block_x + block_width
			, block_y + block_height, GetColor(r, g, b), true);
	}
}

//�㕔�ł̃{�[���̓����蔻��
bool Block::flag_ballhit_up(int Ball_x, int Ball_y) {

	//��ʂɑ��݂��Ă���
	if (flag_remove == 0) {
		//�㕔�ɓ��������ꍇ
		if (((Ball_y + ball_size) >= block_y) && ((Ball_y - ball_size) <= block_y)
			&& ((Ball_x > block_x) && (Ball_x < (block_x + block_width)))) {
			flag_remove = 1;
			return true;
		}
		else {
			return false;
		}
	}
	//�����Ă�
	else {
		return false;
	}
}

//�����ł̃{�[���̓����蔻��
bool Block::flag_ballhit_down(int Ball_x, int Ball_y) {
	//��ʂɂ���
	if (flag_remove == 0) {
		//�����ɓ��������ꍇ
		if (((Ball_y - ball_size) <= (block_y + block_height)) && ((Ball_y + ball_size) >= (block_y + block_height))
			&& ((Ball_x > block_x) && (Ball_x < (block_x + block_width)))) {
			flag_remove = 1;
			return true;
		}
		else {
			return false;
		}
	}
	//���݂��Ȃ�
	else {
		return false;
	}
}

//���Ń{�[���ɓ�������
bool Block::flag_ballhit_left(int Ball_x, int Ball_y) {
	//��ʂɂ���
	if (flag_remove == 0) {
		//���ɓ��������ꍇ
		if (((Ball_x + ball_size) >= block_x) && ((Ball_x - ball_size) <= block_x)
			&& (Ball_y >= block_y) && (Ball_y <= (block_y + block_height))) {
			flag_remove = 1;
			return true;
		}
		else {
			return false;
		}
	}
	//���݂��Ȃ�
	else {
		return false;
	}
}
//�E�Ń{�[���ɓ�������
bool Block::flag_ballhit_right(int Ball_x, int Ball_y) {
	//��ʂɂ���
	if (flag_remove == 0) {
		//�E�ɓ��������ꍇ
		if (((Ball_x - ball_size) <= (block_x + block_width))
			&& ((Ball_x + ball_size) >= (block_x + block_width))
			&& (Ball_y >= block_y) && (Ball_y <= (block_y + block_height))) {
			flag_remove = 1;
			return true;
		}
		else {
			return false;
		}
	}
	//���݂��Ȃ�
	else {
		return false;
	}
}