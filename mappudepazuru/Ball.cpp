#include "DxLib.h"
#include <iostream>
#include "Ball.h"
#include "Bar.h"

using namespace std;

//コンストラクト
Ball::Ball() {
	this->ball_x = 325;
	this->ball_y = 394;
	this->WHF_x = 0;			//右壁に当たった(WallHitFlag
	this->WHF_y = 0;			//下壁に当たった(WallHitFlag
	this->ball_speed = 3;		//ボールの速度
}


//ボールの速度を変えれるコンストラクト
Ball::Ball(int ball_speed){

	this->ball_x = 325;
	this->ball_y = 394;
	this->WHF_x = 0;			//右壁に当たった(WallHitFlag
	this->WHF_y = 0;			//下壁に当たった(WallHitFlag
	this->ball_speed = ball_speed;
}


//デストラクト
Ball::~Ball(){}

//バーに当たったら
void Ball::BarHit() {
	WHF_y = 1;
}

//ブロックの上部にあったら
void Ball::BlockHit_Up() {
	WHF_y = 1;
}

//ブロックの下部にあたったら
void Ball::BlockHit_Down() {
	WHF_y = 0;
}

//ブロックの左に当たったら
void Ball::BlockHit_Left() {
	WHF_x = 1;
}

//ブロックの右に当たったら
void Ball::BlockHit_Right() {
	WHF_x = 0;
}

//ボールの描画
void Ball::Ball_Draw() {

	DrawCircle(ball_x, ball_y, ball_size, GetColor(255, 255, 255), true);
}


//ボールの更新
void Ball::Ball_Update() {

	//右壁にぶつかっていない
	if (WHF_x == 0){
		ball_x = ball_x + ball_speed;
	}
	//右壁にぶつかったら
	else {
		ball_x = ball_x - ball_speed;
	}

	//下壁にぶつかっていない
	if (WHF_y == 0) {
		ball_y = ball_y + ball_speed;
	}
	//下壁にぶつかったら
	else {
		ball_y = ball_y - ball_speed;
	}


	//右壁にぶつかった瞬間
	if (ball_x >= 640 - ball_size) {
		WHF_x = 1;
	}

	//左壁にぶつかった瞬間
	if (ball_x <= ball_size) {
		WHF_x = 0;
	}

	//上壁にぶつかった瞬間
	if (ball_y <= ball_size) {
		WHF_y = 0;
	}
	/*//下壁にぶつかった瞬間
	if (ball_y >= 480 - ball_size) {
		WHF_y = 1;
	}*/
}

//ボールのｘ座標ゲッター
int Ball::get_x() {
	return ball_x;
}

//ボールのｙ座標ゲッター
int Ball::get_y() {
	return ball_y;
}