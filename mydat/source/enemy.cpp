/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#include "../include/GV.h"

//敵の移動パターン0での移動制御
void enemy_pattern0(int i) {
	int t = enemy[i].cnt;
	if (t == 0) {
		//下がってくる
		enemy[i].vy = 2;
	}
	if (t == 60) {
		//止まる
		enemy[i].vy = 0;
	}
	//登録された停滞時間だけして
	if (t == 60 + enemy[i].wait) {
		//上がっていく
		enemy[i].vy = -2;
	}
}

//空いている敵番号を検索
int enemy_num_search(){
	//フラグのたって無いenemyを探す
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i].flag == 0) {
			//使用可能番号を返す
			return i;
		}
	}
	//全部埋まっていたらエラーを返す
	return -1;
}

//敵情報を登録
//敵の行動を登録・制御する関数
void enemy_enter() {
	for (int t = 0; t < ENEMY_ORDER_MAX; t++) {
		//現在の瞬間がオーダーの瞬間なら
		if (enemy_order[t].cnt == stage_count) {
			int i;
			if ((i = enemy_num_search()) != -1) {
				enemy[i].flag = 1;									//フラグ
				enemy[i].cnt = 0;									//カウンタ
				enemy[i].pattern = enemy_order[t].pattern;			//移動パターン
				enemy[i].muki = 1;									//向き
				enemy[i].knd = enemy_order[t].knd;					//敵の種類
				enemy[i].x = enemy_order[t].x;						//座標
				enemy[i].y = enemy_order[t].y;
				enemy[i].sp = enemy_order[t].sp;					//スピード
				enemy[i].bltime = enemy_order[t].bltime;			//弾の発射時間
				enemy[i].blknd = enemy_order[t].blknd;				//弾幕の種類
				enemy[i].blknd2 = enemy_order[t].blknd2;			//弾の種類
				enemy[i].col = enemy_order[t].col;					//色
				enemy[i].wait = enemy_order[t].wait;				//
				enemy[i].hp = enemy_order[t].hp;					//体力
				enemy[i].hp_max = enemy[i].hp;						//体力最大値
				enemy[i].vx = 0;									//水平成分の速度
				enemy[i].vy = 0;									//鉛直成分の速度
				enemy[i].ang = 0;									//角度
				for (int j = 0; j < 6; j++) {
					enemy[i].item_n[j] = enemy_order[t].item_n[j];	//落とすアイテム
				}
			}
		}
	}
}

//敵の行動制御
void enemy_act() {
	for (int i = 0; i < ENEMY_MAX; i++) {
		//その敵のフラグがオンになってたら
		if (enemy[i].flag == 1) {
			enemy_pattern0(i);
			enemy[i].x += cos(enemy[i].ang) * enemy[i].sp;
			enemy[i].y += sin(enemy[i].ang) * enemy[i].sp;
			enemy[i].x += enemy[i].vx;
			enemy[i].y += enemy[i].vy;
			enemy[i].cnt++;
			enemy[i].img = enemy[i].muki * 3 + (enemy[i].cnt % 18) / 6;
			//敵が画面外に外れたら消す
			if (enemy[i].x < -50 ||
				FIELD_MAX_X + 50 < enemy[i].x ||
				enemy[i].y < -50 ||
				FIELD_MAX_Y + 50 < enemy[i].y) {
				enemy[i].flag = 0;
			}
		}
	}
}

//敵処理メイン
void enemy_main() {
    enemy_enter();
    enemy_act();
}