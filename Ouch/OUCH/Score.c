/******************************************************************************/
/*!
\file   Score.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the functions used for displaying time taken screen
*/
/******************************************************************************/

#pragma once
#include "Score.h"
#include "Timer.h"
#include "GameStateManager.h"
#include "Windows.h"
#include "Enemy.h"

/* Initialise */
void Score_Init()
{
	Enemy_Init();
	system("cls");
	Timer_SaveStageTimer();
	Timer_DisplayTotalTimeTaken(30, 9);
}

/* Update Loop */
void Score_Update()
{
	/* Enter to continue to next stage */
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		GameStateManager_NextLevel();
	}
}