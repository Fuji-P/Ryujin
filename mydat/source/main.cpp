/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#define GLOBAL_INSTANCE 
#include "../include/GV.h"

int Key[256];

int GetHitKeyStateAll_2(
	int GetHitKeyStateAll_InputKey[]
	)
{
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll(GetHitKeyStateAll_Key);

	for (int i = 0; i < 256; i++) {
		if (GetHitKeyStateAll_Key[i] == 1) {
			GetHitKeyStateAll_InputKey[i]++;
		}
		else {
			GetHitKeyStateAll_InputKey[i] = 0;
		}
	}
	return 0;
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	)
{
	//ウィンドウモード
	ChangeWindowMode(TRUE);

	//初期化と裏画面化
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) {
		return -1;
	}

	while (
			ProcessMessage() == 0 &&					//ﾒｯｾｰｼﾞ処理
			ClearDrawScreen() == 0 &&					//画面をｸﾘｱ
			GetHitKeyStateAll_2(Key) == 0 &&			//入力状態を保存
			Key[KEY_INPUT_ESCAPE] == 0					//ESCが押されていない
			) {

			//ココ！！

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}
