#include "EndScene.h"
#include "DxLib.h"
#include "SceneManager.h"

int End_image;
int wait_count;

#define SCREEN_HEIGHT (720)
#define SCREEN_WIDTH (1280)

/*********************************************************
	�G���h��ʁ@�F�@����������
	���@���@�F�@�Ȃ�
	�߂�l�@�F�@�Ȃ�
**********************************************************/

int EndScene_Initialize(void)
{
	int ret = 0;

	End_image = LoadGraph("images/end.bmp");

	if (End_image == -1)
	{
		ret = -1;
	}

	wait_count = 0;

	return ret;
}


/*********************************************************
	�u���b�N�@�\�@�F�@�X�V����
	���@���@�F�@�Ȃ�
	�߂�l�@�F�@�Ȃ�
**********************************************************/

void EndScene_Update(void)
{
	wait_count++;
}


/*********************************************************
	�u���b�N�@�\�@�F�@�`�揈��
	���@���@�F�@�Ȃ�
	�߂�l�@�F�@�Ȃ�
**********************************************************/

void EndScene_Draw(void)
{
	DrawExtendGraph(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, End_image, TRUE);
}

/*********************************************************
	�G���h�@�\�@�F�@�C���m�F����
	���@���@�F�@�Ȃ�
	�߂�l�@�F�@�Ȃ�
**********************************************************/

int Get_EndTime(void)
{
	if (wait_count > 300)
	{
		return TRUE;
	}
	return FALSE;
}