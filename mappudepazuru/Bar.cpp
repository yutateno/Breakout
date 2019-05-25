#include "DxLib.h"
#include <iostream>
#include "Bar.h"
#include "Ball.h"

using namespace std;

//�R���X�g���N�g
Bar::Bar() {
	this->bar_x = 300;
}

//�f�X�g���N�g
Bar::~Bar() {

}

//�X�V
void Bar::Bar_Update(int ball_x) {
	//�E�ɓ���
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0 && (bar_x + bar_width) < 640) {
		bar_x += bar_speed;
	}
	//���ɓ���
	if (CheckHitKey(KEY_INPUT_LEFT) != 0 && bar_x > 0) {
		bar_x -= bar_speed;
	}
	//�����ŉE�ɓ���
	if ((bar_x + bar_width) < 640 && (bar_x + (bar_width / 2)) < ball_x) {
		bar_x += bar_speed;
	}
	//�����ō��ɓ���
	if (bar_x > 0 && (bar_x + (bar_width / 2)) >= ball_x) {
		bar_x -= bar_speed;
	}
}

//�`��
void Bar::Bar_Draw() {
	DrawBox(bar_x, bar_y, bar_x + bar_width
		, bar_y + bar_height, GetColor(255, 0, 0), true);
}

//�o�[�̏�ɓ���������
bool Bar::flag_ballhit(int ball_X, int ball_Y) {
	//�o�[�̏�Ƀ{�[����������
	if (((ball_Y + ball_size) >= bar_y) && ((ball_Y + ball_size) <= (bar_y + bar_height))
		&& ((ball_X > bar_x) && (ball_X < (bar_x + bar_width)))) {
		return 1;
	}
	else {
		return 0;
	}
}