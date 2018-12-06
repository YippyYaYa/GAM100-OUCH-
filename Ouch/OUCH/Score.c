#pragma once
#include "Score.h"
#include "Timer.h"
#include "GameStateManager.h"
#include "Windows.h"
#include "Enemy.h"

void Score_Init()
{
	Enemy_Init();
	system("cls");
	Timer_SaveStageTimer();
	Timer_DisplayTotalTimeTaken(30, 9);
}

void Score_Update()
{
	/* Enter to continue to next stage */
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		GameStateManager_NextLevel();
	}
}