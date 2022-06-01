/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
/****************************************/

#define GLOBAL_INSTANCE 
#include "../include/GV.h"

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
	//���݂̃p�b�h���͏������s��
	GetHitPadStateAll();
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

		switch(func_state){
			case 0:
				load();				//�f�[�^���[�h
				first_ini();		//����̏�����
				func_state = 99;
				break;
			//STG���n�߂�O�ɍs��������
			case 99:
				ini();
				load_story();
				func_state = 100;
				break;
			case 100:
				calc_ch();			//�L�����N�^�v�Z
				ch_move();			//�L�����N�^�̈ړ�����
				enemy_main();		//�G�������C��
				graph_main();		//�`�惁�C��
				stage_count++;
				break;
			default:
				printfDx("�s����func_state\n");
				break;
			}

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
