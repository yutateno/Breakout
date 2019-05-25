#include "DxLib.h"
#include <iostream>
#include "Block.h"

using namespace std;

//コンストラクト
Block::Block() {
	block_x = 0;
	block_y = 0;
	r = 125, g = 125, b = 125;
	flag_remove = 0;
}

//ブロックの位置を引数に取ったコンストラクト
Block::Block(int block_x, int block_y) {
	this->block_x = block_x;
	this->block_y = block_y;
	r = GetRand(254) + 1, g = GetRand(254) + 1, b = GetRand(254) + 1;
	flag_remove = 0;
}

//デストラクト
Block::~Block() {

}


//更新（いらない
void Block::Block_Update() {
	count++;
	if (count % 10 == 0 && count != 0) {
		block_y += (block_height / 3);
	}
	if (block_y >= 480) {
		block_y = 0;
	}
}

//描画
void Block::Block_Draw() {
	//画面に存在してたら
	if (flag_remove == 0) {
		DrawBox(block_x, block_y, block_x + block_width
			, block_y + block_height, GetColor(r, g, b), true);
	}
}

//上部でのボールの当たり判定
bool Block::flag_ballhit_up(int Ball_x, int Ball_y) {

	//画面に存在してたら
	if (flag_remove == 0) {
		//上部に当たった場合
		if (((Ball_y + ball_size) >= block_y) && ((Ball_y - ball_size) <= block_y)
			&& ((Ball_x > block_x) && (Ball_x < (block_x + block_width)))) {
			flag_remove = 1;
			return true;
		}
		else {
			return false;
		}
	}
	//消えてる
	else {
		return false;
	}
}

//下部でのボールの当たり判定
bool Block::flag_ballhit_down(int Ball_x, int Ball_y) {
	//画面にいる
	if (flag_remove == 0) {
		//下部に当たった場合
		if (((Ball_y - ball_size) <= (block_y + block_height)) && ((Ball_y + ball_size) >= (block_y + block_height))
			&& ((Ball_x > block_x) && (Ball_x < (block_x + block_width)))) {
			flag_remove = 1;
			return true;
		}
		else {
			return false;
		}
	}
	//存在しない
	else {
		return false;
	}
}

//左でボールに当たった
bool Block::flag_ballhit_left(int Ball_x, int Ball_y) {
	//画面にいる
	if (flag_remove == 0) {
		//左に当たった場合
		if (((Ball_x + ball_size) >= block_x) && ((Ball_x - ball_size) <= block_x)
			&& (Ball_y >= block_y) && (Ball_y <= (block_y + block_height))) {
			flag_remove = 1;
			return true;
		}
		else {
			return false;
		}
	}
	//存在しない
	else {
		return false;
	}
}
//右でボールに当たった
bool Block::flag_ballhit_right(int Ball_x, int Ball_y) {
	//画面にいる
	if (flag_remove == 0) {
		//右に当たった場合
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
	//存在しない
	else {
		return false;
	}
}