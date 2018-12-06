/******************************************************************************/
/*!
\file   Timer.c
\author Chew Wei Fa Alex
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
Timer.c is in charge of the time taken by the player to clear each stage and
the total time the player took to clear all the stage.
*/
/******************************************************************************/
#include "Timer.h"
#include <stdio.h>

/*This file is to make functions for calcualating time passed and display the time*/
static float time = 0;
static float totalTime = 0;

/*Init the time to 0*/
void Timer_Init_StageTimer()
{
	time = 0;
}
/*Init total time*/
void Timer_InitTotalTime()
{
	totalTime = 0;
}
/*This function will be called in the loop*/
void Timer_UpdateTimer(float dt)
{
	time = time + dt;
}
/*This function will also be called in the loop*/
void Timer_DisplayStageTime(int x, int y)
{
	WindowsHelper_SetCursorPosition(x, y);
	printf("%4.1f seconds", time);
}

/*Call this before moving on to next stage and init - Stages 0 to TotalStages-1*/
void Timer_SaveStageTimer()
{
	totalTime += time;
}

/*Stages 0 to TotalStages-1*/
void Timer_DisplayTotalTimeTaken(int x, int y)
{
	WindowsHelper_SetCursorPosition(x, y);
	printf("You cleared the stage in %4.1f seconds!", time);
	WindowsHelper_SetCursorPosition(x, y+1); /*print below */
	printf("You have used %4.1f seconds since level 1.", totalTime);
}