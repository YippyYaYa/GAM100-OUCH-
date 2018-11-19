#pragma once
#include "Game.h"
#include "Grid.h"
#include "Enemy.h"
#include "Player.h"
#include "GameStateManager.h"

static int currentStage;
static int totalStages;

/*Init game and pass in game level file i/o*/
void Game_Init()
{
	system("cls");
	currentStage = 2;	   
	totalStages = 3;
	Game_LoadLevel(currentStage);
}

/*Update game*/
void Game_Update(float dt)
{
	Player_Controls(dt);
	Enemy_Update(dt);
	/* Check if player collided with enemy */
	if (Player_DeathCheck())
	{
		GameStateManager_SetGameState(GameOver);
	}
}

void Game_LoadLevel(int level)
{
	if (level != 0)
	{
		currentStage = level;
	}
	Enemy_Init();
	Grid_initGrid(currentStage);
	Grid_printGrid();
	switch (currentStage)
	{
	case 1:
		break;
	case 2:
		Enemy_Spawn(9, 12, 'U', 'R', 15);
		Enemy_Spawn(19, 15, 'R', 'R', 15);
		Enemy_Spawn(45, 1, 'R', 'R', 15);
		Enemy_Spawn(40, 3, 'R', 'R', 15);
		Enemy_Spawn(12, 17, 'R', 'R', 15);
		Enemy_Spawn(85, 2, 'R', 'R', 15);

		Player_InitPlayer();
		Player_SetPosition(1, 1);
		break;
	case 3:
		/* init enemy/switch/obstacle/wutever non grid objects here */
		Enemy_Spawn(2, 3, 'R', 'B', 5);
		Enemy_Spawn(3, 4, 'R', 'B', 5);
		Enemy_Spawn(4, 5, 'R', 'B', 5);
		Enemy_Spawn(5, 6, 'R', 'B', 5);
		Enemy_Spawn(6, 7, 'R', 'B', 5);
		Enemy_Spawn(7, 8, 'R', 'B', 5);
		Enemy_Spawn(8, 9, 'R', 'B', 5);
		Enemy_Spawn(9, 10, 'R', 'B', 5);
		Enemy_Spawn(18, 15, 'R', 'B', 5);
		Enemy_Spawn(1, 16, 'R', 'B', 5);
		Enemy_Spawn(18, 17, 'R', 'B', 5);
		Enemy_Spawn(1, 18, 'R', 'B', 5);
		Enemy_Spawn(14, 10, 'U', 'B', 5);
		Enemy_Spawn(16, 10, 'D', 'B', 5);
		Enemy_Spawn(18, 10, 'D', 'B', 5);
		Enemy_Spawn(20, 6, 'D', 'B', 5);
		Enemy_Spawn(21, 10, 'D', 'B', 5);
		Enemy_Spawn(72, 18, 'R', 'B', 5);
		Enemy_Spawn(37, 7, 'R', 'B', 5);
		Enemy_Spawn(35, 5, 'L', 'B', 5);
		Enemy_Spawn(81, 7, 'R', 'B', 5);
		Enemy_Spawn(91, 5, 'D', 'B', 5);
		Enemy_Spawn(94, 13, 'D', 'B', 5);

		Player_InitPlayer();
		Player_SetPosition(1, 1);
		break;
	case 4:
		Enemy_Spawn(17, 9, 'D', 'R', 1);
		Enemy_Spawn(14, 6, 'L', 'B', 5);
		Enemy_Spawn(22, 2, 'D', 'B', 2);
		Enemy_Spawn(32, 3, 'U', 'R', 2);
		Enemy_Spawn(12, 3, 'U', 'R', 2);
		Enemy_Spawn(30, 12, 'R', 'R', 2);
		Enemy_Spawn(61, 7, 'U', 'R', 2);
		Enemy_Spawn(30, 12, 'U', 'R', 2);
		Enemy_Spawn(37, 9, 'R', 'R', 2);
		Enemy_Spawn(62, 9, 'R', 'B', 1);
		Enemy_Spawn(23, 15, 'R', 'B', 2);
		Enemy_Spawn(46, 17, 'R', 'B', 2);
		Enemy_Spawn(62, 15, 'L', 'R', 5);
		Enemy_Spawn(62, 14, 'R', 'R', 5);
		Enemy_Spawn(72, 17, 'L', 'R', 5);

		Player_InitPlayer();
		Player_SetPosition(13, 9);

		break;
	case 5:
		break;
	}
}

void Game_LevelComplete()
{
	if (currentStage + 1 > (currentStage + totalStages - 1))
	{
		GameStateManager_SetGameState(MainMenu);
	}
	else
	{
		currentStage++;
		Game_LoadLevel(currentStage);
	}
}