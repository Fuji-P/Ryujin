/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#include "../include/GV.h"

//敵描画
void graph_enemy() {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i].flag == 1) {
			DrawRotaGraphF((float)enemy[i].x + FIELD_X, (float)enemy[i].y + FIELD_Y, 1.0f, 0.0f, img_enemy[0][enemy[i].img], TRUE);
		}
	}
}

//自機描画
void graph_ch() {
	DrawRotaGraphF((float)ch.x + FIELD_X, (float)ch.y + FIELD_Y, 1.0f, 0.0f, img_ch[0][ch.img], TRUE);
}

//自機ショット描画
void graph_cshot(){
	for (int i = 0; i < CSHOT_MAX; i++){
		if (cshot[i].flag > 0){
			DrawRotaGraphF((float)cshot[i].x + FIELD_X, (float)cshot[i].y + FIELD_Y, 1, 0, img_cshot[cshot[i].knd], TRUE);
		}
	}
}

//弾丸の描画
void graph_bullet() {
	//線形補完描画
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	//敵の弾幕数分ループ
	for (int i = 0; i < SHOT_MAX; i++) {
		//弾幕データがオンなら
		if (shot[i].flag > 0) {
			//その弾幕が持つ弾の最大数分ループ
			for (int j = 0; j < SHOT_BULLET_MAX; j++) {
				//弾データがオンなら
				if (shot[i].bullet[j].flag != 0) {
					if (shot[i].bullet[j].eff == 1) {
						SetDrawBlendMode(DX_BLENDMODE_ADD, 255);

					}
					DrawRotaGraphF(
						(float)shot[i].bullet[j].x + FIELD_X,
						(float)shot[i].bullet[j].y + FIELD_Y,
						1.0,
						shot[i].bullet[j].angle + PI / 2,
						img_bullet[shot[i].bullet[j].knd][shot[i].bullet[j].col],
						TRUE
						);
					if (shot[i].bullet[j].eff == 1) {
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					}
				}
			}
		}
	}
	//描画形式を戻す
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

void graph_board(){
	DrawGraph(0, 0, img_board[10], FALSE);
	DrawGraph(0, 16, img_board[11], FALSE);
	DrawGraph(0, 464, img_board[12], FALSE);
	DrawGraph(416, 0, img_board[20], FALSE);
}

void graph_main() {
	graph_enemy();
	graph_cshot();
	graph_ch();
	graph_bullet();
	graph_board();
}