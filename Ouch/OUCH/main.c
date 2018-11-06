#pragma once
#include "WindowsHelper.h"
#include <time.h>
#include "GameStateManager.h"

int main(void)
{
	clock_t ticksThen, ticksNow;
	float timePassed;
	ticksThen = clock();
	/*Engine Initialise*/
	/* Initialise Console grid*/
	WindowsHelper_Init();
	
	/*Initialise Game*/
	GameStateManager_Init();
	while (GameStateManager_GetCurrentState() != Quit)
	{
		ticksNow = clock();
		timePassed = (ticksNow - ticksThen) / (float)CLOCKS_PER_SEC;
		if (timePassed >= 0.016f)
		{
			ticksThen = ticksNow;
			GameStateManager_Update(timePassed);
		}
	}
	getch();
	return 0;
}