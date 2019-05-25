#include "DxLib.h"
#include <iostream>
#include "Ball.h"
#include "Bar.h"

using namespace std;

//�R���X�g���N�g
Ball::Ball() {
	this->ball_x = 325;
	this->ball_y = 394;
	this->WHF_x = 0;			//�E�ǂɓ�������(WallHitFlag
	this->WHF_y = 0;			//���ǂɓ�������(WallHitFlag
	this->ball_speed = 3;		//�{�[���̑��x
}


//�{�[���̑��x��ς����R���X�g���N�g
Ball::Ball(int ball_speed){

	this->ball_x = 325;
	this->ball_y = 394;
	this->WHF_x = 0;			//�E�ǂɓ�������(WallHitFlag
	this->WHF_y = 0;			//���ǂɓ�������(WallHitFlag
	this->ball_speed = ball_speed;
}


//�f�X�g���N�g
Ball::~Ball(){}

//�o�[�ɓ���������
void Ball::BarHit() {
	WHF_y = 1;
}

//�u���b�N�̏㕔�ɂ�������
void Ball::BlockHit_Up() {
	WHF_y = 1;
}

//�u���b�N�̉����ɂ���������
void Ball::BlockHit_Down() {
	WHF_y = 0;
}

//�u���b�N�̍��ɓ���������
void Ball::BlockHit_Left() {
	WHF_x = 1;
}

//�u���b�N�̉E�ɓ���������
void Ball::BlockHit_Right() {
	WHF_x = 0;
}

//�{�[���̕`��
void Ball::Ball_Draw() {

	DrawCircle(ball_x, ball_y, ball_size, GetColor(255, 255, 255), true);
}


//�{�[���̍X�V
void Ball::Ball_Update() {

	//�E�ǂɂԂ����Ă��Ȃ�
	if (WHF_x == 0){
		ball_x = ball_x + ball_speed;
	}
	//�E�ǂɂԂ�������
	else {
		ball_x = ball_x - ball_speed;
	}

	//���ǂɂԂ����Ă��Ȃ�
	if (WHF_y == 0) {
		ball_y = ball_y + ball_speed;
	}
	//���ǂɂԂ�������
	else {
		ball_y = ball_y - ball_speed;
	}


	//�E�ǂɂԂ������u��
	if (ball_x >= 640 - ball_size) {
		WHF_x = 1;
	}

	//���ǂɂԂ������u��
	if (ball_x <= ball_size) {
		WHF_x = 0;
	}

	//��ǂɂԂ������u��
	if (ball_y <= ball_size) {
		WHF_y = 0;
	}
	/*//���ǂɂԂ������u��
	if (ball_y >= 480 - ball_size) {
		WHF_y = 1;
	}*/
}

//�{�[���̂����W�Q�b�^�[
int Ball::get_x() {
	return ball_x;
}

//�{�[���̂����W�Q�b�^�[
int Ball::get_y() {
	return ball_y;
}