/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2

//敵の当たり判定範囲
int enemy_range[ENEMY_RANGE_MAX] = {16, 30, 16, 50};
//自機ショットの当たり判定範囲
int cshot_range[CSHOT_RANGE_MAX] = {6,};

//当たったかどうかを判定する
int out_judge_cshot(
	int i,
	int s
)
{
	//ショットの軌道が１度でも計算されていたら
	if (cshot[i].cnt > 0) {
		
		//敵と自機ショットとの距離
		double x = cshot[i].x - enemy[s].x;
		double y = cshot[i].y - enemy[s].y;
		
		//オーバーフロー対策
		if (cshot[i].knd >= CSHOT_RANGE_MAX || 
			enemy[s].knd >= ENEMY_RANGE_MAX) {
			printfDx("out_judge_cshot内オーバーフロー");
		}
		
		//敵の当たり判定と自機ショットの当たり判定の合計範囲
		int r = cshot_range[cshot[i].knd] + enemy_range[enemy[s].knd];
		
		//中間を計算する必要があれば
		if (cshot[i].spd > r) {

			//１フレーム前にいた位置を格納する
			double pre_x = cshot[i].x + cos(cshot[i].angle + PI) * cshot[i].spd;
			double pre_y = cshot[i].y + sin(cshot[i].angle + PI) * cshot[i].spd;
			double px;
			double py;

			//進んだ分÷当たり判定分ループ
			for (int j = 0; j < cshot[i].spd / r; j++) {
				px = pre_x - enemy[s].x;
				py = pre_y - enemy[s].y;
				if (px * px + py * py < r * r) {
					return 1;
				}
				pre_x += cos(cshot[i].angle) * r;
				pre_y += sin(cshot[i].angle) * r;
			}
		}
		//当たり判定内なら
		if (x * x + y * y < r * r) {
			//当たり
			return 1;
		}
	}
	return 0;
}

//敵が死ぬかどうかの決定
void enemy_death_judge(
	int s
)
{
	//敵に当たった音
	se_flag[8] = 1;

	//敵のHPが０未満になったら
	if (enemy[s].hp < 0) {

		//敵を消滅させる
		enemy[s].flag = 0;
		//敵のピチュリ音
		se_flag[1] = 1;

		//敵総数分
		for (int i = 0; i < SHOT_MAX; i++) {
			//登録されている弾幕データがあれば
			if (shot[i].flag != 0) {
				//その敵が登録した弾幕があれば
				if (s == shot[i].num) {
					//それ以上弾幕を続けないフラグを立てる
					shot[i].flag = 2;
					break;
				}
			}
		}
	}
}

//当たり判定メイン
void out_main() {
	//自機ショット総数
	for (int i = 0; i < CSHOT_MAX; i++) {
		if (cshot[i].flag > 0) {
			//敵総数
			for (int s = 0; s < ENEMY_MAX; s++) {
				if (enemy[s].flag > 0) {
					//自機ショットと敵が当たっていれば
					if (out_judge_cshot(i, s)) {
						//その自機ショットを消す
						cshot[i].flag = 0;
						//弾の持つパワー分HPを減らす
						enemy[s].hp -= cshot[i].power;
						//敵が死ぬかどうかを決める
						enemy_death_judge(s);
					}
				}
			}
		}
	}
}