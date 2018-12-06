#include "Timer.h"
#include <stdio.h>

/*This file is to make functions for calcualating time passed and display the time*/
static float time = 0;
static float level[STAGES];

/*Init the time to 0*/
void Init_StageTimer()
{
	time = 0;
}
/*This function will be called in the loop*/
void StartStageTimer(float dt)
{
	time = time + dt;
}
/*This function will also be called in the loop*/
void DisplayStageTime(int x, int y)
{
	WindowsHelper_SetCursorPosition(x, y);
	printf("%d seconds", time);
}

/*Call this before moving on to next stage and init - Stages 0 to TotalStages-1*/
void SaveStageTimer(int Stage)
{
	level[Stage] = time;
}

/*Stages 0 to TotalStages-1*/
void DisplayTotalTimeTaken(int x, int y, int Stage)
{
	int i;
	float total = 0;
	for (i = 0; i < Stage+1; i++)
		total += level[i];
	WindowsHelper_SetCursorPosition(x, y);
	printf("You cleared the stage in %d seconds!\n", level[Stage]);
	printf("You have used %d seconds since level 1.", total);
}