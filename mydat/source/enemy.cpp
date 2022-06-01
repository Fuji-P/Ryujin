/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
/****************************************/

#include "../include/GV.h"

//�G�̈ړ��p�^�[��0�ł̈ړ�����
void enemy_pattern0(int i) {
	int t = enemy[i].cnt;
	if (t == 0) {
		//�������Ă���
		enemy[i].vy = 2;
	}
	if (t == 60) {
		//�~�܂�
		enemy[i].vy = 0;
	}
	//�o�^���ꂽ��؎��Ԃ�������
	if (t == 60 + enemy[i].wait) {
		//�オ���Ă���
		enemy[i].vy = -2;
	}
}

//�󂢂Ă���G�ԍ�������
int enemy_num_search(){
	//�t���O�̂����Ė���enemy��T��
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i].flag == 0) {
			//�g�p�\�ԍ���Ԃ�
			return i;
		}
	}
	//�S�����܂��Ă�����G���[��Ԃ�
	return -1;
}

//�G����o�^
//�G�̍s����o�^�E���䂷��֐�
void enemy_enter() {
	for (int t = 0; t < ENEMY_ORDER_MAX; t++) {
		//���݂̏u�Ԃ��I�[�_�[�̏u�ԂȂ�
		if (enemy_order[t].cnt == stage_count) {
			int i;
			if ((i = enemy_num_search()) != -1) {
				enemy[i].flag = 1;									//�t���O
				enemy[i].cnt = 0;									//�J�E���^
				enemy[i].pattern = enemy_order[t].pattern;			//�ړ��p�^�[��
				enemy[i].muki = 1;									//����
				enemy[i].knd = enemy_order[t].knd;					//�G�̎��
				enemy[i].x = enemy_order[t].x;						//���W
				enemy[i].y = enemy_order[t].y;
				enemy[i].sp = enemy_order[t].sp;					//�X�s�[�h
				enemy[i].bltime = enemy_order[t].bltime;			//�e�̔��ˎ���
				enemy[i].blknd = enemy_order[t].blknd;				//�e���̎��
				enemy[i].blknd2 = enemy_order[t].blknd2;			//�e�̎��
				enemy[i].col = enemy_order[t].col;					//�F
				enemy[i].wait = enemy_order[t].wait;				//
				enemy[i].hp = enemy_order[t].hp;					//�̗�
				enemy[i].hp_max = enemy[i].hp;						//�̗͍ő�l
				enemy[i].vx = 0;									//���������̑��x
				enemy[i].vy = 0;									//���������̑��x
				enemy[i].ang = 0;									//�p�x
				for (int j = 0; j < 6; j++) {
					enemy[i].item_n[j] = enemy_order[t].item_n[j];	//���Ƃ��A�C�e��
				}
			}
		}
	}
}

//�G�̍s������
void enemy_act() {
	for (int i = 0; i < ENEMY_MAX; i++) {
		//���̓G�̃t���O���I���ɂȂ��Ă���
		if (enemy[i].flag == 1) {
			enemy_pattern0(i);
			enemy[i].x += cos(enemy[i].ang) * enemy[i].sp;
			enemy[i].y += sin(enemy[i].ang) * enemy[i].sp;
			enemy[i].x += enemy[i].vx;
			enemy[i].y += enemy[i].vy;
			enemy[i].cnt++;
			enemy[i].img = enemy[i].muki * 3 + (enemy[i].cnt % 18) / 6;
			//�G����ʊO�ɊO�ꂽ�����
			if (enemy[i].x < -50 ||
				FIELD_MAX_X + 50 < enemy[i].x ||
				enemy[i].y < -50 ||
				FIELD_MAX_Y + 50 < enemy[i].y) {
				enemy[i].flag = 0;
			}
		}
	}
}

//�G�������C��
void enemy_main() {
    enemy_enter();
    enemy_act();
}