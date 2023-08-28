#include "DxLib.h"
#include "InputControl.h"

//�ϐ�����
int old_button;
int now_button;
int mouse_position_x;
int mouse_position_y;

//�v���g�^�C�v�錾�B�B�B�B�B�B�B�B�B�B�B�B�B�B




void Input_Initialize(void)
{
	old_button = NULL;
	now_button = NULL;
	mouse_position_x = NULL;
	mouse_position_y = NULL;
}

void Input_Update(void)
{
	//�}�E�X���͏��̎擾
	old_button = now_button;
	now_button = GetMouseInput();

	//�J�[�\���̍��W
	GetMousePoint(&mouse_position_x, &mouse_position_y);
}


int Input_Escape(void)
{
	int ret = FALSE;

	//ESC�L�[�������ꂽ�烋�[�v���甲����
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;
}

int GetOldKey(int key)
{
	int ret = FALSE;
	if ((key & old_button) != FALSE)
	{
		ret = TRUE;
	}

	return ret;
}

int GetNowKey(int key)
{
	int ret = FALSE;

	if ((key & now_button) != FALSE)
	{
		ret = TRUE;
	}

	return ret;
}

int GetKeyFlg(int key)
{
	int ret = FALSE;
	int keyflg = now_button & ~old_button;

	if ((key & keyflg) != FALSE)
	{
		ret = TRUE;
	}
	return ret;
}

int GetMousePositionX(void)
{
	return mouse_position_x;
}

int GetMousePositionY(void)
{
	return mouse_position_y;
}