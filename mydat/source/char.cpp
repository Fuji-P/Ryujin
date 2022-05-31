/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#include "../include/GV.h"

void calc_ch(){
	ch.cnt++;
	ch.img = (ch.cnt % 24) / 6;
}

void ch_move() {
	int sayu_flag = 0;
	int joge_flag = 0;
	int inputpad[4];
	double x;
	double y;
	double mx;
	double my;
	double naname = 1;
	double move_x[4] = {-4.0, 4.0, 0,0};
	double move_y[4] = {0, 0, 4.0, -4.0};

	inputpad[0] = CheckStatePad(configpad.left);
	inputpad[1] = CheckStatePad(configpad.right);
	inputpad[2] = CheckStatePad(configpad.down);
	inputpad[3] = CheckStatePad(configpad.up);

	//左キーが押されていたら
	if (CheckStatePad(configpad.left) > 0) {
		//画像を左向きに
		ch.img += 4 * 2;
	}
	//右キーが押されていたら
	else if (CheckStatePad(configpad.right) > 0) {
		//画像を右向きに
		ch.img += 4 * 1;
	}

	//左右分
	for (int i = 0; i < 2; i++) {
		//左右どちらかの入力があれば
		if (inputpad[i] > 0) {
			//左右入力フラグを立てる
			sayu_flag = 1;
		}
	}

	//上下分
	for (int i = 2; i < 4; i++) {
		//上下どちらかの入力があれば
		if (inputpad[i] > 0) {
			//上下入力フラグを立てる
			joge_flag = 1;
		}
	}

	//左右、上下両方の入力があれば斜めだと言う事
	if (sayu_flag == 1 && joge_flag == 1) {
		//移動スピードを1/ルート2に
		naname = sqrt(2.0);
	}

	//4方向分ループ
	for (int i = 0; i < 4; i++) {
		//i方向のキーボード、パッドどちらかの入力があれば
		if (inputpad[i] > 0) {
			//今の座標をとりあえずx,yに格納
			x = ch.x;
			y = ch.y;
			//移動分をmx,myに代入
			mx = move_x[i];
			my = move_y[i];
			//低速移動なら
			if (CheckStatePad(configpad.slow) > 0) {
				//移動スピードを1/3に
				mx = move_x[i] / 3;
				my = move_y[i] / 3;
			}
			//今の座標と移動分を足す
			x += mx / naname;
			y += my / naname;
			//計算結果移動可能範囲内なら
			if (!(x<10 || x>FIELD_MAX_X - 10 || y<5 || y>FIELD_MAX_Y - 5)) {
				//実際に移動させる
				ch.x = x;
				ch.y = y;
			}
		}
	}
}