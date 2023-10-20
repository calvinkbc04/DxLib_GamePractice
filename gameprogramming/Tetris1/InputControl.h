#pragma once


void InputControl_Initialize(void);
void InputControl_Update(void);

int GetButton(int button);
int GetButtonDown(int button);
int GetButtonUp(int button);

int GetExitButton(void);