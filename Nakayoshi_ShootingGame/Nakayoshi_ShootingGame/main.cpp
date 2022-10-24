#include<DxLib.h>
#include"SceneManager.h"
#include"GameMainScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// �^�C�g���� test �ɕύX
	SetMainWindowText("�V���[�e�B���O�Q�[��");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	//�^�C�g���摜�f�[�^�̓ǂݍ���
	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�
	SceneManager sceneMng( dynamic_cast <AbstractScene*>(new GameMainScene()));

	// �Q�[�����[�v
	while (ProcessMessage() == 0) {

		

		ClearDrawScreen();		// ��ʂ̏�����
		sceneMng.Update();		//�V�[���̍X�V
		sceneMng.Draw();		//�V�[���̕`��

		if (sceneMng.ChangeScene() == nullptr) {//�V�[���̕ύX
			DxLib_End();	

			return 0;
		}

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

	}


	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}