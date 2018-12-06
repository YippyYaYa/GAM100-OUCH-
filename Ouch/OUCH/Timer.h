#pragma once
#include "WindowsHelper.h"
#define STAGES 5

void Init_StageTimer();
void StartStageTimer(float dt);
void DisplayStageTime(int x, int y);
void SaveStageTimer(int Stage);
void DisplayTotalTimeTaken(int x, int y);