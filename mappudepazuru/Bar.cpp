#include "DxLib.h"
#include <iostream>
#include "Bar.h"
#include "Ball.h"

using namespace std;

//コンストラクト
Bar::Bar() {
	this->bar_x = 300;
}

//デストラクト
Bar::~Bar() {

}

//更新
void Bar::Bar_Update(int ball_x) {
	//右に動く
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0 && (bar_x + bar_width) < 640) {
		bar_x += bar_speed;
	}
	//左に動く
	if (CheckHitKey(KEY_INPUT_LEFT) != 0 && bar_x > 0) {
		bar_x -= bar_speed;
	}
	//自動で右に動く
	if ((bar_x + bar_width) < 640 && (bar_x + (bar_width / 2)) < ball_x) {
		bar_x += bar_speed;
	}
	//自動で左に動く
	if (bar_x > 0 && (bar_x + (bar_width / 2)) >= ball_x) {
		bar_x -= bar_speed;
	}
}

//描画
void Bar::Bar_Draw() {
	DrawBox(bar_x, bar_y, bar_x + bar_width
		, bar_y + bar_height, GetColor(255, 0, 0), true);
}

//バーの上に当たったら
bool Bar::flag_ballhit(int ball_X, int ball_Y) {
	//バーの上にボールが当たる
	if (((ball_Y + ball_size) >= bar_y) && ((ball_Y + ball_size) <= (bar_y + bar_height))
		&& ((ball_X > bar_x) && (ball_X < (bar_x + bar_width)))) {
		return 1;
	}
	else {
		return 0;
	}
}