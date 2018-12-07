/******************************************************************************/
/*!
\file   main.c
\author Chong Yi Fang, Alex Chew
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the main loop of the whole game
*/
/******************************************************************************/

#pragma once
#include "WindowsHelper.h"    /* To set initial console size */
#include <time.h>             /* For clock() */
#include "GameStateManager.h" /* Game state control */
#include "Colours.h"          /* For initialising colours system */

int main(void)
{
	clock_t ticksThen, ticksNow; /* For loop time */
	float timePassed;            /* Time between each update */

	ticksThen = clock();

	/*** Engine Initialise ***/
	/* Initialise Console grid*/
	WindowsHelper_Init();

	/* Initialise Color system */
	Colours_Init();
	
	/*Initialise Game*/
	GameStateManager_Init();

	/* Game Loop */
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

	return 0;
}