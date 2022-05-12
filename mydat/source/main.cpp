/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
/****************************************/

#define GLOBAL_INSTANCE 
#include "../include/GV.h"

//���݂̃L�[���͏������s��
extern int GetHitKeyStateAll_2();
//�󂯎�����L�[�ԍ��̌��݂̓��͏�Ԃ�Ԃ�
extern int CheckStateKey(unsigned char Handle);
//�f�[�^�̃��[�h
extern void load();
//�`�惁�C��
extern void graph_main();

int img_ch[2][12];	//�L�����N�^�摜9�����@X2(�ϐg�p)
ch_t ch;			//�L�����N�^�f�[�^�錾

//���[�v�ŕK���s���R�又��
int ProcessLoop()
{
	//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if (ProcessMessage() != 0) {
		return -1;
	}
	//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	if (ClearDrawScreen() != 0) {
		return -1;
	}
	//���݂̃L�[���͏������s��
	GetHitKeyStateAll_2();
	return 0;
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	)
{
	//�E�B���h�E���[�h
	ChangeWindowMode(TRUE);

	//�������Ɨ���ʉ�
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) {
		return -1;
	}

	//�f�[�^���[�h
	load();

	//���C�����[�v
	while (ProcessLoop() == 0) {

		//�`�惁�C��
		graph_main();

		//�G�X�P�[�v�����͂��ꂽ��u���C�N
		if (CheckStateKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		//����ʔ��f
		ScreenFlip();
	}

	//DX���C�u�����I������
	DxLib_End();
	return 0;
}
