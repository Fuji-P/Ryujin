/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#include "../include/GV.h"

//敵の移動パターン0での移動制御
void enemy_pattern0(int i) {
    if (enemy[i].cnt < 60) {
        enemy[i].y += 2.0;
    }
    if (enemy[i].cnt > 60 + 240) {
        enemy[i].y -= 2.0;
    }
}

//敵データの登録
void enemy_enter() {
    //ゲームが始まって100カウントで登録
    if (stage_count == 100) {
        enemy[0].cnt = 0;
        enemy[0].muki = 1;
        enemy[0].flag = 1;
        enemy[0].bltime = 150;
        enemy[0].hp = 1000;
        enemy[0].hp_max = enemy[0].hp;
        enemy[0].pattern = 0;
        enemy[0].x = FIELD_MAX_X / 2;
        enemy[0].y = -20;
    }
}

//敵の行動制御
void enemy_act() {
    for (int i = 0; i < ENEMY_MAX; i++) {
        //その敵のフラグがオンになってたら
        if (enemy[i].flag == 1) {
            enemy_pattern0(i);
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