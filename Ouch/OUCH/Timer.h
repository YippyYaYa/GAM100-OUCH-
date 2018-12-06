#pragma once
#include "WindowsHelper.h"
#define STAGES 5

void Timer_Init_StageTimer();
void Timer_InitTotalTime();
void Timer_UpdateTimer(float dt);
void Timer_DisplayStageTime(int x, int y);
void Timer_SaveStageTimer();
void Timer_DisplayTotalTimeTaken(int x, int y);