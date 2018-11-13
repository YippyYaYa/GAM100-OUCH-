#pragma once
#include "Game.h"
#include "Grid.h"
#include "Enemy.h"
#include "Player.h"
#include "GameStateManager.h"
#include <Windows.h>

#define FOREGROUND_CYAN FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE

static int currentStage;

/*Init game and pass in game level file i/o*/
void Game_Init()
{
	system("cls");
	currentStage = 4;
	/* Initialise level 1*/
	Grid_initGrid(currentStage);
	Enemy_Init();

	/*Spawn Enemies*/
	Enemy_Spawn(11, 1, 'R', 'B', 5);
	Enemy_Spawn(1, 2, 'R', 'B', 5);
	Enemy_Spawn(2, 3, 'R', 'B', 5);
	Enemy_Spawn(3, 4, 'R', 'B', 5);
	Enemy_Spawn(4, 5, 'R', 'B', 5);
	Enemy_Spawn(5, 6, 'R', 'B', 5);
	Enemy_Spawn(6, 7, 'R', 'B', 5);
	Enemy_Spawn(7, 8, 'R', 'B', 5);
	Enemy_Spawn(8, 9, 'R', 'B', 5);
	Enemy_Spawn(9, 10, 'R', 'B', 5);
	Enemy_Spawn(1, 11, 'R', 'B', 5);
	Enemy_Spawn(18, 15, 'R', 'B', 5);
	Enemy_Spawn(1, 16, 'R', 'B', 5);
	Enemy_Spawn(18, 17, 'R', 'B', 5);
	Enemy_Spawn(1, 18, 'R', 'B', 5);
	Enemy_Spawn(14, 10, 'U', 'B', 5);
	Enemy_Spawn(16, 10, 'D', 'B', 5);
	Enemy_Spawn(18, 10, 'D', 'B', 5);
	Enemy_Spawn(20, 6, 'D', 'B', 5);
	Enemy_Spawn(21, 10, 'D', 'B', 5);
	Enemy_Spawn(22, 7, 'D', 'B', 1);
	Enemy_Spawn(23, 10, 'D', 'B', 5);
	Enemy_Spawn(72, 18, 'R', 'B', 5);
	Enemy_Spawn(37, 7, 'R', 'B', 5);
	Enemy_Spawn(35, 5, 'L', 'B', 5);

	/*Print Grid and Etc*/
	Grid_printGrid();
	Player_InitPlayer();
	
	///* Color Coding here for future use */

	//* dont touch these just copy it */
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	//WORD saved_attributes;
	///* Save current attributes */
	//GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	//saved_attributes = consoleInfo.wAttributes;
	///* dont touch ends here */

	///*edit foreground and background color here*/
	//SetConsoleTextAttribute(hConsole, FOREGROUND_CYAN);
	//printf("This is some nice COLORFUL text, isn't it?");

	///* Restore original attributes */
	//SetConsoleTextAttribute(hConsole, saved_attributes);
	//printf("Back to normal");
}

/*Update game*/
void Game_Update(float dt)
{
	Player_Controls();
	Enemy_Update(dt);
	if (Player_DeathCheck())
	{
		GameStateManager_SetGameState(GameOver);
	}
}

void Game_LoadLevel(int level)
{
	currentStage = level;
	Grid_initGrid(currentStage);
	switch (currentStage)
	{
		case 2:
			/* init enemy/switch/obstacle/wutever non grid objects here */
			Player_SetPosition(1, 1);
			break;
		case 3:
			break;
		case 4:
			break;
	}
}