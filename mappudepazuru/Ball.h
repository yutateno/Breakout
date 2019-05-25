#pragma once

class Ball {

private:

	const int ball_size = 6;//ボールの大きさ
	int ball_x;				//ボールのｘ座標
	int ball_y;				//ボールのｙ座標
	bool WHF_x;				//右壁に当たった(WallHitFlag
	bool WHF_y;				//下壁に当たった(WallHitFlag
	int ball_speed;			//ボールの速度

public:

	Ball();					//コンストラクト
	Ball(int ball_speed);	//ボールの速度変えれるコンストラクト
	~Ball();				//デストラクト
	void BarHit();			//バーに当たる
	void BlockHit_Up();		//ブロックの上に当たる
	void BlockHit_Down();	//ブロックの下に当たる
	void BlockHit_Left();	//ブロックの左に当たる
	void BlockHit_Right();	//ブロックの右に当たる
	void Ball_Draw();		//描画
	void Ball_Update();		//更新
	int get_x();			//ボールのｘ座標取得
	int get_y();			//ボールのｙ座標取得
};