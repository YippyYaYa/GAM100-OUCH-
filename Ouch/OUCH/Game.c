#pragma once
#include "Game.h"
#include "Grid.h"
#include "Enemy.h"
#include "Player.h"
#include "GameStateManager.h"
#include <Windows.h>
#include <stdio.h>

static int currentStage;

/*Init game and pass in game level file i/o*/
void Game_Init()
{
	system("cls");
	currentStage = 4;

	Enemy_Init();

	Game_LoadLevel(4);
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
	Grid_printGrid();
	switch (currentStage)
	{
	case 1:
		break;
	case 2:
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

		Player_InitPlayer();
		Player_SetPosition(1, 1);
		break;
	case 4:
		Enemy_Spawn(10, 18, 'R', 'B', 5);
		break;
	case 5:
		break;
	}
}