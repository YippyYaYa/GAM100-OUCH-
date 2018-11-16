#pragma once
#include "Loading.h"
#include "GameStateManager.h"
#include <Windows.h>
#include <stdio.h>
#include "Grid.h"
#include "Colours.h"

/* variables here, must be static */
static float tPass;
static int count = 0;
void Loading_Init()
{
	Colours_SetColor(RED);
	system("cls");
	Grid_initGrid(6);
	Grid_printGrid();
	Colours_ResetColor();
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
		Grid_initGrid(7);
		Grid_printGrid();
	}
	if(tPass > 7.0f)
	GameStateManager_SetGameState(MainMenu);
	
}

/* function definitions here */