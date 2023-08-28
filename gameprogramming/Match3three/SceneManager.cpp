#include "SceneManager.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"


//�}�N����`�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B


//�^��`�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B


//�ϐ���`
GAME_MODE Game_Mode;
GAME_MODE Next_Mode;

//�v���g�^�C�v�錾�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B


int SceneManager_Initialize(GAME_MODE mode)
{
	int Read_Error;
	switch (mode)
	{
	case (E_TITLE):
		Read_Error = TitleScene_Initialize();
		if (Read_Error == D_ERROR)
		{
			return D_ERROR;
		}
		break;
		
	case (E_GAMEMAIN):
		Read_Error = GameMainScene_Initialize();
		if (Read_Error == D_ERROR)
		{
			return D_ERROR;
		}
		break;

	case (E_GAME_CLEAR):
		Read_Error = GameClearScene_Initialize();
		if (Read_Error == D_ERROR)
		{
			return D_ERROR;
		}
		break;

	case (E_GAME_OVER):
		Read_Error = GameOverScene_Initialize();
		if (Read_Error == D_ERROR)
		{
			return D_ERROR;
		}
		break;
	}
	Game_Mode = mode;
	Next_Mode = Game_Mode;

	return Read_Error;
}

void SceneManager_Update(void)
{
	if (Game_Mode != Next_Mode)
	{
		SceneManager_Initialize(Next_Mode);
	}

	switch (Game_Mode)
	{
	case E_TITLE:
		TitleScene_Update();
		break;
	
	case E_GAMEMAIN:
		GameMainScene_Update();
		break;
	
	case E_GAME_CLEAR:
		GameClearScene_Update();
		break;

	case E_GAME_OVER:
		GameOverScene_Update();
		break;
	
	default:
		break;
	}
}

void SceneManager_Draw(void)
{
	switch (Game_Mode)
	{
	case E_TITLE:
		TitleScene_Draw();
		break;

	case E_GAMEMAIN:
		GameMainScene_Draw();
		break;

	case E_GAME_CLEAR:
		GameClearScene_Draw();
		break;

	case E_GAME_OVER:
		GameOverScene_Draw();
		break;

	default:
		break;
	}
}

void Change_Scene(GAME_MODE mode)
{
	Next_Mode = mode;
}