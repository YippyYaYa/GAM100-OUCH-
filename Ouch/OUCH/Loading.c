#pragma once
#include "Loading.h"
#include "GameStateManager.h"
#include <Windows.h>
#include <stdio.h>
#include "Grid.h"

/* variables here, must be static */
static float tPass;
static int count = 0;
void Loading_Init()
{
	system("cls");
	Grid_initGrid(6);
	Grid_printGrid();
}

void Loading_Update(float dt)
{
	/* do stuff here */
	tPass = tPass + dt;
	/* Change state*/
/*	if(count == 0)                this shit is annoying when debugging
	if (tPass > 4.0f)             your code is perfect but just keep it off
	{
		count++;
		Grid_initGrid(7);
		Grid_printGrid();
	}
	if(tPass > 7.0f) */
	GameStateManager_SetGameState(MainMenu);
}

/* function definitions here */