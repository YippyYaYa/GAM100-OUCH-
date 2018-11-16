#include "LevelLoader.h"
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include <Windows.h>

static int currentLevel;

void LevelLoader_Init()
{
	currentLevel = 0;
}

void LevelLoader_LoadLevel(int level)
{
	system("cls");
	currentLevel = level;
	Grid_initGrid(currentLevel);
	
	/* Object and Enemy Spawning */
	switch (level)
	{
		case 4:
			Grid_printGrid();
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
	}
}