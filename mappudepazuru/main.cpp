#include "DxLib.h"
#include <iostream>
#include "Breakout.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);

	Breakout *breakout = new Breakout(6, 160);	//ボールのスピード、ブロックの数

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
	
		breakout->Breakout_Update();
		breakout->Breakout_Draw();
	}


	delete breakout;

	DxLib_End();
	return 0;
}