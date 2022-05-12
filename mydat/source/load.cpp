/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#include "../include/GV.h"

extern int img_ch[2][12];

void load() {
	LoadDivGraph("dat/img/char/0.png", 12, 4, 3, 73, 73, img_ch[0]);
}