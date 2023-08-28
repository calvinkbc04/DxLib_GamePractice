#include "GameClearScene.h"
#include "DxLib.h"
#include "SceneManager.h"

//�}�N����`�B�B�B�B�B�B�B�B�B�B�B�B�B


//�^��`�B�B�B�B�B�B�B�B�B�B�B�B�B


//�ϐ��錾
int GameClearImage;
int GameClearSE;
int GameClearFlag;

//�v���g�^�C�v�錾�B�B�B�B�B�B�B�B�B�B�B�B�B


int GameClearScene_Initialize(void)
{
	int ret = 0;

	//�摜�̓ǂݍ���
	GameClearImage = LoadGraph("images/gameclear.png");
	//�����̓ǂݍ���
	GameClearSE = LoadSoundMem("sounds/gameclear_se.mp3");

	GameClearFlag = 0;


	//�G���[�`�F�b�N
	if (GameClearImage == -1)
	{
		ret = -1;
	}
	if (GameClearSE == -1)
	{
		ret = -1;
	}

	return ret;
}

void GameClearScene_Update(void)
{
	//�Q�[���N���A���ʉ��Đ��`�F�b�N
	if (CheckSoundMem(GameClearSE) == 0)
	{
		if (GameClearFlag == TRUE)
		{
			Change_Scene(E_GAMEMAIN);
		}
		else
		{
			PlaySoundMem(GameClearSE, DX_PLAYTYPE_BACK);
			GameClearFlag = TRUE;
		}
	}
}

void GameClearScene_Draw(void)
{
	DrawGraph(0, 0, GameClearImage, FALSE);
}