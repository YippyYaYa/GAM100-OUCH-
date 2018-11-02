#pragma once
#include <stdio.h>
#include <windows.h>
#include "WindowsHelper.h"
#include "Grid.h"
#include "Player.h"
#include "Game.h"
#include <time.h>


int main(void)
{
	clock_t timeThen, timeNow;
	float timePassed;
	timeThen = clock();
	/*Engine Initialise*/
	/* Initialise Console grid*/
	WindowsHelper_Init();

	/*Initialise Game*/
	Game_InitGame();

	Game_setCurrentState(Playing);

	while (Game_getCurrentState() != Quit)
	{
		timeNow = clock();
		timePassed = (timeThen - timeNow) / (float)CLOCKS_PER_SEC;
		Game_Update();
	}

	return 0;
}