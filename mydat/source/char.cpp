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