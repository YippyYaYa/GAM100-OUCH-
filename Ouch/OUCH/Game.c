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
	currentStage = 1;
	/* Initialise level 1*/
	Grid_initGrid(currentStage);
	Enemy_init(0, 2, 2, 'D', 'R');
	Enemy_init(1, 70, 7, 'R', 'B');
	Grid_printGrid();
	Player_InitPlayer();
	
	///* Color Coding here dont touch*/

	///* dont touch these just copy it */
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
void Game_Update()
{
	Player_Controls();
	Enemy_Update();
}