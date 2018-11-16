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
	Grid_initGrid(0);
	Grid_printGrid();
}

void Loading_Update(float dt)
{
	/* do stuff here */
	tPass = tPass + dt;
	/* Change state*/
	if(count == 0)
	if (tPass > 4.0f)
	{
		count++;
		Grid_initGrid(1);
		Grid_printGrid();
	}
	if(tPass > 7.0f)
	GameStateManager_SetGameState(MainMenu);
	
}

/* function definitions here */