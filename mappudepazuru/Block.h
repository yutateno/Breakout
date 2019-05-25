#pragma once

class Block {

private:

	const int block_width = 80;	//ブロックの横幅
	const int ball_size = 6;	//ボールのサイズ
	const int block_height = 12;//ブロックの縦幅
	int block_x;				//ブロックのｘ座標
	int block_y;				//ブロックのｙ座標
	int r, g, b;				//色
	int count;					//ゆっくり下げていく
	bool flag_remove;			//ボールに当たったら消す(１なら消す

public:

	Block();										//コンストラクト
	Block(int block_x, int block_y);				//座標指定するコンストラクト
	~Block();										//デストラクト
	void Block_Update();							//更新
	void Block_Draw();								//描画
	bool flag_ballhit_up(int Ball_x, int Ball_y);	//上でボールに当たったフラッグ
	bool flag_ballhit_down(int Ball_x, int Ball_y);	//下でボールに当たったフラッグ
	bool flag_ballhit_left(int Ball_x, int Ball_y);	//左でボールに当たったフラッグ
	bool flag_ballhit_right(int Ball_x, int Ball_y);//右でボールに当たったフラッグ
};