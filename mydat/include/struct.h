/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
/****************************************/

//�L�����N�^�[�Ɋւ���\����
typedef struct {
	int flag;			//�t���O
	int cnt;			//�J�E���^
	int power;			//�p���[
	int point;			//�|�C���g
	int score;			//�X�R�A
	int num;			//�c�@��
	int mutekicnt;		//���G��ԂƃJ�E���g
	int shot_mode;		//�V���b�g���[�h
	int money;			//����
	int img;			//�摜
	int slow;			//�X���[���ǂ���
	float x, y;			//���W
//	double x, y;		//���W
}ch_t;

//�p�b�h�Ɋւ���\����
typedef struct{
	int key[PAD_MAX];
}pad_t;

//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left;
	int up;
	int right;
	int down;
	int shot;
	int bom;
	int slow;
	int start;
	int change;
}configpad_t;