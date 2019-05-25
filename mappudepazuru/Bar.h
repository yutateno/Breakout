#pragma once

class Bar {

private:

	const int bar_y = 400;		//バーのｙ座標適当
	const int bar_speed = 15;	//バーの速さ適当
	const int bar_width = 50;	//バーの横幅適当
	const int bar_height = 10;	//バーの高さ適当
	const int ball_size = 6;	//ボールのサイズ
	int bar_x;					//バーのｘ座標

public:

	Bar();										//コンストラクト
	~Bar();										//デストラクト
	void Bar_Update(int ball_y);				//更新
	void Bar_Draw();							//描画
	bool flag_ballhit(int ball_X, int ball_Y);	//ボールの当たりフラッグ
};