/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

#include "../include/GV.h"

void music_ini() {
	memset(se_flag, 0, sizeof(int) * SE_MAX);
}

void music_play() {
	for (int i = 0; i < SE_MAX; i++) {
		if (se_flag[i] == 1) {
			PlaySoundMem(sound_se[i], DX_PLAYTYPE_BACK);
		}
	}
}