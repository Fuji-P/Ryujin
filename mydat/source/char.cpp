/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
/****************************************/

#include "../include/GV.h"

void calc_ch(){
	ch.cnt++;
	ch.img = (ch.cnt % 24) / 6;
	if (CheckStatePad(configpad.left) > 0) {
		ch.x -= 3;
	}
	if (CheckStatePad(configpad.right) > 0) {
		ch.x += 3;
	}
}
