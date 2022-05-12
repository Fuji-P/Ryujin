/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#define GLOBAL_INSTANCE 
#include "../include/GV.h"

//現在のキー入力処理を行う
extern int GetHitKeyStateAll_2();
//受け取ったキー番号の現在の入力状態を返す
extern int CheckStateKey(unsigned char Handle);
//データのロード
extern void load();
//描画メイン
extern void graph_main();

int img_ch[2][12];	//キャラクタ画像9枚分　X2(変身用)
ch_t ch;			//キャラクタデータ宣言

//ループで必ず行う３大処理
int ProcessLoop()
{
	//プロセス処理がエラーなら-1を返す
	if (ProcessMessage() != 0) {
		return -1;
	}
	//画面クリア処理がエラーなら-1を返す
	if (ClearDrawScreen() != 0) {
		return -1;
	}
	//現在のキー入力処理を行う
	GetHitKeyStateAll_2();
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

	//データロード
	load();

	//メインループ
	while (ProcessLoop() == 0) {

		//描画メイン
		graph_main();

		//エスケープが入力されたらブレイク
		if (CheckStateKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		//裏画面反映
		ScreenFlip();
	}

	//DXライブラリ終了処理
	DxLib_End();
	return 0;
}
