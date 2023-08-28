#include "FreamControl.h"
#include "DxLib.h"

//�}�N����`�B�B�B�B�B�B�B�B�B�B�B�B�B


//�^��`�B�B�B�B�B�B�B�B�B�B�B�B�B


//�萔��`�B�B�B�B�B�B�B�B�B�B�B�B�B


//�ϐ��錾
int FreamTime;
int NowTime;
int Wait;
int LastTime;

//�v���g�^�C�v�錾�B�B�B�B�B�B�B�B�B�B�B�B�B



void FreamControl_Initialize(void)
{
	FreamTime = ((int)1000.0f / FREAM_RATE);
	NowTime = 0;
	Wait = 0;
	LastTime = 0;
}

void FreamControl_Update(void)
{
	NowTime = GetNowCount();
	Wait = FreamTime - (NowTime - LastTime);

	if (Wait > 0)
	{
		WaitTimer(Wait);
	}
	LastTime = GetNowCount();
}
