/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#define GLOBAL_INSTANCE 
#include "../include/GV.h"

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
	//現在のパッド入力処理を行う
	GetHitPadStateAll();
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

		switch(func_state){
			case 0:
				//データロード
				load();
				//初回の初期化
				first_ini();
				func_state=100;
				break;
			case 100:
				//キャラクタ計算
				calc_ch();
				//キャラクタの移動制御
				ch_move();
				//描画メイン
				graph_main();
				break;
			default:
				printfDx("不明なfunc_state\n");
				break;
			}

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
