/****************************************/
/* �����    �FDixq                     */
/* �T�[�N�����FRemicalSoft              */
/* �T�C�g��  �F���_�^�v���O���~���O�̊� */
/****************************************/

#define GLOBAL_INSTANCE 
#include "../include/GV.h"

int Key[256];

int GetHitKeyStateAll_2(
	int GetHitKeyStateAll_InputKey[]
	)
{
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll(GetHitKeyStateAll_Key);

	for (int i = 0; i < 256; i++) {
		if (GetHitKeyStateAll_Key[i] == 1) {
			GetHitKeyStateAll_InputKey[i]++;
		}
		else {
			GetHitKeyStateAll_InputKey[i] = 0;
		}
	}
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

	while (
			ProcessMessage() == 0 &&					//ү���ޏ���
			ClearDrawScreen() == 0 &&					//��ʂ�ر
			GetHitKeyStateAll_2(Key) == 0 &&			//���͏�Ԃ�ۑ�
			Key[KEY_INPUT_ESCAPE] == 0					//ESC��������Ă��Ȃ�
			) {

			//�R�R�I�I

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}
