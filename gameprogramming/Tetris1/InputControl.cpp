#include "InputControl.h"
#include "DxLib.h"

/*********************************************************
	マクロ定義
**********************************************************/

#define XINPUT_BUTTON_MAX	(16)

/*********************************************************
	型定義
**********************************************************/

enum KEY_STATE
{
	E_NONE,
	E_CLICK,
	E_PRESS,
	E_RELEASED,
	E_KEY_STATE_MAX
};

/*********************************************************
	変数宣言
**********************************************************/
KEY_STATE button_state[XINPUT_BUTTON_MAX];

/*********************************************************
入力制限機能：初期化処理
引　数：なし
戻り値：なし
**********************************************************/
void InputControl_Initialize(void)
{
	int i;

	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		button_state[i] = E_NONE;
	}
}

/*********************************************************
	入力制御機能　：　更新処理
	引　数　：　なし
	戻り値　：　なし
**********************************************************/
void InputControl_Update(void)
{
	int i;								//ループカウンタ
	XINPUT_STATE input_controller;		//コントローラー入力情報

	//コントローラーの入力情報
	GetJoypadXInputState(DX_INPUT_PAD1, &input_controller);

	//入力状態の更新
	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		if (input_controller.Buttons[i] == TRUE)
		{
			switch (button_state[i])
			{
			case E_NONE:
			case E_RELEASED:
				button_state[i] = E_CLICK;
				break;
			case E_CLICK:
			case E_PRESS:
				button_state[i] = E_PRESS;
				break;
			default:
				button_state[i] = E_NONE;
				break;
			}
		}
		else
		{
			switch (button_state[i])
			{
			case E_NONE:
			case E_RELEASED:
				button_state[i] = E_NONE;
				break;
			case E_CLICK:
			case E_PRESS:
				button_state[i] = E_RELEASED;
				break;
			default:
				button_state[i] = E_NONE;
				break;
			}
		}
	}
}

int GetButton(int button)
{
	int ret = FALSE;
	if (button_state[button] == E_CLICK || button_state[button] == E_PRESS)
	{
		ret = TRUE;
	}
	return ret;
}

int GetButtonDown(int button)
{
	int ret = FALSE;
	if (button_state[button] == E_CLICK)
	{
		ret = TRUE;
	}

	return ret;
}

int GetButtonUp(int button)
{
	int ret = FALSE;
	if (button_state[button] == E_RELEASED)
	{
		ret = TRUE;
	}
	return ret;
}

int GetExitButton(void)
{
	int ret = FALSE;

	if ((GetButtonDown(XINPUT_BUTTON_BACK) == TRUE) || (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE))
	{
		ret = TRUE;
	}
	return ret;
}