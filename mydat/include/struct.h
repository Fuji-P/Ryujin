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
	double x, y;		//���W
}ch_t;

//�G�Ɋւ���\����
typedef struct {
	int flag;			//�t���O
	int cnt;			//�J�E���^
	int pattern;		//�ړ��p�^�[��
	int muki;			//����
	int knd;			//�G�̎��
	int hp;				//HP
	int hp_max;			//HP�ő�l
	int item_n[6];		//���Ƃ��A�C�e��
	int img;			//
	double x;			//���W
	double y;			//���W
	double vx;			//���xx����
	double vy;			//���xy����
	double sp;			//�X�s�[�h
	double ang;			//�p�x
	int bltime;			//�e���J�n����
	int blknd;			//�e���̎��
	int blknd2;			//�e�̎��
	int col;			//�F
	int state;			//���
	int wtime;			//�ҋ@����
	int wait;			//��؎���
}enemy_t;

typedef struct {
	int cnt;			//�J�E���^
	int pattern;		//�ړ��p�^�[��
	int knd;			//�G�̎��
	double x;			//�������W
	double y;			//�������W
	double sp;			//�ړ��X�s�[�h
	int bltime;			//�e���J�n����
	int blknd;			//�e���̎��
	int col;			//�F
	int hp;				//�̗�
	int blknd2;			//�e�̎��
	int wait;			//��؎���
	int item_n[6];		//�A�C�e��(6���)
}enemy_order_t;

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