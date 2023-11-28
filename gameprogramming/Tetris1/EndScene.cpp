#include "EndScene.h"
#include "DxLib.h"
#include "SceneManager.h"

int End_image;
int wait_count;

#define SCREEN_HEIGHT (720)
#define SCREEN_WIDTH (1280)

/*********************************************************
	エンド画面　：　初期化処理
	引　数　：　なし
	戻り値　：　なし
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
	ブロック機能　：　更新処理
	引　数　：　なし
	戻り値　：　なし
**********************************************************/

void EndScene_Update(void)
{
	wait_count++;
}


/*********************************************************
	ブロック機能　：　描画処理
	引　数　：　なし
	戻り値　：　なし
**********************************************************/

void EndScene_Draw(void)
{
	DrawExtendGraph(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, End_image, TRUE);
}

/*********************************************************
	エンド機能　：　修了確認処理
	引　数　：　なし
	戻り値　：　なし
**********************************************************/

int Get_EndTime(void)
{
	if (wait_count > 300)
	{
		return TRUE;
	}
	return FALSE;
}