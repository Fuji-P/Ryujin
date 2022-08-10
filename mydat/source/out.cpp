/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
/****************************************/

#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2

//�G�̓����蔻��͈�
int enemy_range[ENEMY_RANGE_MAX] = {16, 30, 16, 50};
//���@�V���b�g�̓����蔻��͈�
int cshot_range[CSHOT_RANGE_MAX] = {6,};

//�����������ǂ����𔻒肷��
int out_judge_cshot(
	int i,
	int s
)
{
	//�V���b�g�̋O�����P�x�ł��v�Z����Ă�����
	if (cshot[i].cnt > 0) {
		
		//�G�Ǝ��@�V���b�g�Ƃ̋���
		double x = cshot[i].x - enemy[s].x;
		double y = cshot[i].y - enemy[s].y;
		
		//�I�[�o�[�t���[�΍�
		if (cshot[i].knd >= CSHOT_RANGE_MAX || 
			enemy[s].knd >= ENEMY_RANGE_MAX) {
			printfDx("out_judge_cshot���I�[�o�[�t���[");
		}
		
		//�G�̓����蔻��Ǝ��@�V���b�g�̓����蔻��̍��v�͈�
		int r = cshot_range[cshot[i].knd] + enemy_range[enemy[s].knd];
		
		//���Ԃ��v�Z����K�v�������
		if (cshot[i].spd > r) {

			//�P�t���[���O�ɂ����ʒu���i�[����
			double pre_x = cshot[i].x + cos(cshot[i].angle + PI) * cshot[i].spd;
			double pre_y = cshot[i].y + sin(cshot[i].angle + PI) * cshot[i].spd;
			double px;
			double py;

			//�i�񂾕��������蔻�蕪���[�v
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
		//�����蔻����Ȃ�
		if (x * x + y * y < r * r) {
			//������
			return 1;
		}
	}
	return 0;
}

//�G�����ʂ��ǂ����̌���
void enemy_death_judge(
	int s
)
{
	//�G�ɓ���������
	se_flag[8] = 1;

	//�G��HP���O�����ɂȂ�����
	if (enemy[s].hp < 0) {

		//�G�����ł�����
		enemy[s].flag = 0;
		//�G�̃s�`������
		se_flag[1] = 1;

		//�G������
		for (int i = 0; i < SHOT_MAX; i++) {
			//�o�^����Ă���e���f�[�^�������
			if (shot[i].flag != 0) {
				//���̓G���o�^�����e���������
				if (s == shot[i].num) {
					//����ȏ�e���𑱂��Ȃ��t���O�𗧂Ă�
					shot[i].flag = 2;
					break;
				}
			}
		}
	}
}

//�����蔻�胁�C��
void out_main() {
	//���@�V���b�g����
	for (int i = 0; i < CSHOT_MAX; i++) {
		if (cshot[i].flag > 0) {
			//�G����
			for (int s = 0; s < ENEMY_MAX; s++) {
				if (enemy[s].flag > 0) {
					//���@�V���b�g�ƓG���������Ă����
					if (out_judge_cshot(i, s)) {
						//���̎��@�V���b�g������
						cshot[i].flag = 0;
						//�e�̎��p���[��HP�����炷
						enemy[s].hp -= cshot[i].power;
						//�G�����ʂ��ǂ��������߂�
						enemy_death_judge(s);
					}
				}
			}
		}
	}
}