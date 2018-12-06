/******************************************************************************/
/*!
\file   Timer.h
\author Chew Wei Fa Alex
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for Timer.c
*/
/******************************************************************************/
#pragma once
#include "WindowsHelper.h"

void Timer_Init_StageTimer();
void Timer_InitTotalTime();
void Timer_UpdateTimer(float dt);
void Timer_DisplayStageTime(int x, int y);
void Timer_SaveStageTimer();
void Timer_DisplayTotalTimeTaken(int x, int y);