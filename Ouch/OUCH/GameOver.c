#pragma once
#include "GameOver.h"
#include "Grid.h"
#include "GameStateManager.h"
#include <stdio.h>
#include <Windows.h>

static int currentStage;

void GameOver_Init() 
{
	system("cls");
	currentStage = 8;
	Grid_initGrid(currentStage);
	/*Print Grid and Etc*/
	Grid_printGrid();
}

void GameOver_Update() 
{

}