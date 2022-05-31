/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
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

	//���L�[��������Ă�����
	if (CheckStatePad(configpad.left) > 0) {
		//�摜����������
		ch.img += 4 * 2;
	}
	//�E�L�[��������Ă�����
	else if (CheckStatePad(configpad.right) > 0) {
		//�摜���E������
		ch.img += 4 * 1;
	}

	//���E��
	for (int i = 0; i < 2; i++) {
		//���E�ǂ��炩�̓��͂������
		if (inputpad[i] > 0) {
			//���E���̓t���O�𗧂Ă�
			sayu_flag = 1;
		}
	}

	//�㉺��
	for (int i = 2; i < 4; i++) {
		//�㉺�ǂ��炩�̓��͂������
		if (inputpad[i] > 0) {
			//�㉺���̓t���O�𗧂Ă�
			joge_flag = 1;
		}
	}

	//���E�A�㉺�����̓��͂�����Ύ΂߂��ƌ�����
	if (sayu_flag == 1 && joge_flag == 1) {
		//�ړ��X�s�[�h��1/���[�g2��
		naname = sqrt(2.0);
	}

	//4���������[�v
	for (int i = 0; i < 4; i++) {
		//i�����̃L�[�{�[�h�A�p�b�h�ǂ��炩�̓��͂������
		if (inputpad[i] > 0) {
			//���̍��W���Ƃ肠����x,y�Ɋi�[
			x = ch.x;
			y = ch.y;
			//�ړ�����mx,my�ɑ��
			mx = move_x[i];
			my = move_y[i];
			//�ᑬ�ړ��Ȃ�
			if (CheckStatePad(configpad.slow) > 0) {
				//�ړ��X�s�[�h��1/3��
				mx = move_x[i] / 3;
				my = move_y[i] / 3;
			}
			//���̍��W�ƈړ����𑫂�
			x += mx / naname;
			y += my / naname;
			//�v�Z���ʈړ��\�͈͓��Ȃ�
			if (!(x<10 || x>FIELD_MAX_X - 10 || y<5 || y>FIELD_MAX_Y - 5)) {
				//���ۂɈړ�������
				ch.x = x;
				ch.y = y;
			}
		}
	}
}