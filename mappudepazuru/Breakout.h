#pragma once
#include "Ball.h"
#include "Bar.h"
#include "Block.h"
#include <vector>

using namespace std;

class Breakout {
private:
	const int block_weight = 80;//ブロックのｘ座標の長
	const int block_height = 12;//ブロックのｙ座標の長さ
	int block_x;				//ブロックのx
	int block_y;				//ブロックのy
	int block_num;				//ブロックの数
	int num;
	Ball *ball;					//ボール
	Bar *bar;					//バー
	vector<Block> block;		//vectorは元からnew deleteしてるらしいからポインタじゃない

public:

	Breakout();								//コンストラクト
	Breakout(int ball_speed, int block_n);	//ボールのスピードとブロックの数を指定できるコンストラクト
	~Breakout();							//デストラクト
	void Breakout_Update();					//更新
	void Breakout_Draw();					//描画
};