#pragma once
#include "WindowsHelper.h"
#include <time.h>
#include "GameStateManager.h"


int main(void)
{
	clock_t timeThen, timeNow;
	float timePassed;
	timeThen = clock();
	/*Engine Initialise*/
	/* Initialise Console grid*/
	WindowsHelper_Init();

	/*Initialise Game*/
	GameStateManager_Init();

	while (GameStateManager_GetCurrentState() != Quit)
	{
		timeNow = clock();
		timePassed = (timeThen - timeNow) / (float)CLOCKS_PER_SEC;
		GameStateManager_Update();
	}

	return 0;
}