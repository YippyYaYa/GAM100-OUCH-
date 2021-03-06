/******************************************************************************/
/*!
\file   Player.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright � 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the functions used for player controls
*/
/******************************************************************************/

#include "Player.h"
#include "WindowsHelper.h"
#include "Grid.h"
#include <windows.h>
#include <stdio.h>
#include "Colours.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "Game.h"
#include "GameStateManager.h"

/* Private variables*/
static int playerX, playerY;            /* Player Coordinates */
static int possessRange;                /* Possession Range */
static char player;                     /* Player Character */
static enum PlayerMode currentMode;     /* Current Form of the Player*/
static enum Direction currentDirection; /* Current direction that player is facing */
static int rhinoBreakCount;             /* Number of times rhino break can be used */
static int debug;

/*Initialise Player position*/
void Player_InitPlayer()
{
	debug = 0;
	possessRange = 5;
	player = 'M';
	currentMode = Monkey;
	currentDirection = Up;
	rhinoBreakCount = 0;
}

/*Check for player input*/
void Player_Controls()
{
	Player_PrintInfo();
	Player_Move();
	Player_Interact();
}

/* Player Movement */
void Player_Move()
{
	/*Left Key Entered*/
	if (GetAsyncKeyState(VK_LEFT) & 0x1)
	{
		currentDirection = Left;
		/* Check if new position is valid */
		if (!Collision_Check(playerX - 1, playerY))
		{
			/* Print over the current position */
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));
			/* Change position */
			playerX--;
			/* Print player on new position */
			Player_PrintPlayer();
		}	
	}
	/*Right Key Entered*/
	else if (GetAsyncKeyState(VK_RIGHT) & 0x1)
	{
		currentDirection = Right;
		/* Check if new position is valid */
		if (!Collision_Check(playerX + 1, playerY))
		{
			/* Print over the current position */
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));
			/* Change position */
			playerX++;
			/* Print player on new position */
			Player_PrintPlayer();
		}
	}
	/*Up Key Entered*/
	else if (GetAsyncKeyState(VK_UP) & 0x1)
	{
		currentDirection = Up;
		/* Check if new position is valid */
		if (!Collision_Check(playerX, playerY - 1))
		{
			/* Print over the current position */
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));
			/* Change position */
			playerY--;
			/* Print player on new position */
			Player_PrintPlayer();
		}
	}
	/*Down Key Entered*/
	else if (GetAsyncKeyState(VK_DOWN) & 0x1)
	{
		currentDirection = Down;
		/* Check if new position is valid */
		if (!Collision_Check(playerX, playerY + 1))
		{
			/* Print over the current position */
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));
			/* Change position */
			playerY++;
			/* Print player on new position */
			Player_PrintPlayer();
		}
	}
}

/* Interaction */
void Player_Interact()
{
	/* Spacebar Entered */
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		switch (currentMode)
		{
			case Monkey:
				Player_Monkey();
				break;
			case Bear:
				Player_Bear();
				break;
			case Rhino:
				Player_Rhino();
				break;
		}
	}
	/* C Key Entered, cancel posession */
	else if (GetAsyncKeyState(0x43) & 0x8000)
	{
		/* Unpossess if current form is rhino or bear */
		switch (currentMode)
		{
			case Rhino:
			case Bear:
				Player_Unpossess();
				break;
		}
	}
	/* R Key Entered, reset stage */
	else if (GetAsyncKeyState(0x52) & 0x8000)
	{
		GameStateManager_RestartLevel();
	}
	/* ESC Key Entered, return to main menu */
	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{	
		GameStateManager_SetGameState(MainMenu);
	}
	/* Below keys are for cheats/debugging purposes */
	/* Number 1 Entered, take on rhino form */
	else if (GetAsyncKeyState(0x31) & 0x8000)
	{
		player = 'R';
		currentMode = Rhino;
		rhinoBreakCount = 2;
		Player_PrintPlayer();
	}
	/* Number 2 entered, take on bear form */
	else if (GetAsyncKeyState(0x32) & 0x8000)
	{
		player = 'B';
		currentMode = Bear;
		Player_PrintPlayer();
	}
	/* Number 3 entered, advance to next stage */
	else if (GetAsyncKeyState(0x33) & 0x8000)
	{
		GameStateManager_SetGameState(Score);
	}
	/* Number 4 entered, toggle on/off debug info */
	else if (GetAsyncKeyState(0x34) & 0x1)
	{
		debug = !debug;
		if (!debug)
		{
			WindowsHelper_SetCursorPosition(17, -1);
			printf("                                   ");
		}
	}
}

/* Check if player collided with any enemy */
int Player_DeathCheck()
{
	if (Collision_Enemy(playerX, playerY))
	{
		return 1;
	}
	else if (Grid_getGrid(playerX, playerY) == 'E')
	{
		GameStateManager_SetGameState(Score);
	}
	return 0;
}

/* Monkey Possession */
void Player_Monkey()
{
	switch (currentDirection)
	{
		case Up:
			/* Check if there are any enemy in range */
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				/* Possess if there is a bear or rhino in range */
				if (Collision_Enemy(playerX, playerY - possessRange) == 1)
				{
					/* Print over current position */
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					/* Set new player char */
					player = Grid_getGrid(playerX, playerY - possessRange);
					/* Set the possessed enemy to inactive */
					Enemy_Kill(playerX, playerY - possessRange);
					/* Update player position*/
					playerY -= possessRange;
					/* Print player on possessed enemy's position */
					Player_PrintPlayer();
					
					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
						rhinoBreakCount = 2;
					}
					break;
				}
				else if (Grid_getGrid(playerX, playerY - possessRange) != ' ')
				{
					break;
				}
			}
			break;
		case Down:
			/* Check if there are any enemy in range */
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				/* Possess if there is a bear or rhino in range */
				if (Collision_Enemy(playerX, playerY + possessRange) == 1)
				{
					/* Print over current position */
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					/* Set new player char */
					player = Grid_getGrid(playerX, playerY + possessRange);
					/* Set the possessed enemy to inactive */
					Enemy_Kill(playerX, playerY + possessRange);
					/* Update player position*/
					playerY += possessRange;
					/* Print player on possessed enemy's position */
					Player_PrintPlayer();

					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
						rhinoBreakCount = 2;
					}
					break;
				}
				else if (Grid_getGrid(playerX, playerY + possessRange) != ' ')
				{
					break;
				}
			}
			break;
		case Left:
			/* Check if there are any enemy in range */
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				/* Possess if there is a bear or rhino in range */
				if (Collision_Enemy(playerX - possessRange, playerY) == 1)
				{
					/* Print over current position */
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					/* Set new player char */
					player = Grid_getGrid(playerX - possessRange, playerY);
					/* Set the possessed enemy to inactive */
					Enemy_Kill(playerX - possessRange, playerY);
					/* Update player position*/
					playerX -= possessRange;
					/* Print player on possessed enemy's position */
					Player_PrintPlayer();

					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
						rhinoBreakCount = 2;
					}
					break;
				}
				else if (Grid_getGrid(playerX - possessRange, playerY) != ' ')
				{
					break;
				}
			}
			break;
		case Right:
			/* Check if there are any enemy in range */
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				/* Possess if there is a bear or rhino in range */
				if (Collision_Enemy(playerX + possessRange, playerY) == 1)
				{
					/* Print over current position */
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					/* Set new player char */
					player = Grid_getGrid(playerX + possessRange, playerY);
					/* Set the possessed enemy to inactive */
					Enemy_Kill(playerX + possessRange, playerY);
					/* Update player position*/
					playerX += possessRange;
					/* Print player on possessed enemy's position */
					Player_PrintPlayer();

					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
						rhinoBreakCount = 2;
					}
					break;
				}
				else if (Grid_getGrid(playerX + possessRange, playerY) != ' ')
				{
					break;
				}
			}
			break;
	}
}

/* Check whether wall can be broken and break if possible*/
void Player_Rhino()
{
	switch (currentDirection)
	{
	case Up:
		if (Grid_getGrid(playerX, playerY - 1) == 'd')
		{
			Player_RhinoWallBreak(playerX, playerY - 1);
		}
		break;
	case Down:
		if (Grid_getGrid(playerX, playerY + 1) == 'd')
		{
			Player_RhinoWallBreak(playerX, playerY + 1);
		}
		break;
	case Left:
		if (Grid_getGrid(playerX - 1, playerY) == 'd')
		{
			Player_RhinoWallBreak(playerX - 1, playerY);
		}
		break;
	case Right:
		if (Grid_getGrid(playerX + 1, playerY) == 'd')
		{
			Player_RhinoWallBreak(playerX + 1, playerY);
		}
		break;
	}
}

/* Bear Pushing Obstacle*/
void Player_Bear()
{
	/* Checks if there is space to push the block */
	switch (currentDirection)
	{
	case Up:
		if (Grid_getGrid(playerX, playerY - 1) == 'p' && Grid_getGrid(playerX, playerY - 2) == ' ')
		{
			Player_BearPush(playerX, playerY - 1, playerX, playerY - 2);
		}
		break;
	case Down:
		if (Grid_getGrid(playerX, playerY + 1) == 'p' && Grid_getGrid(playerX, playerY + 2) == ' ')
		{
			Player_BearPush(playerX, playerY + 1, playerX, playerY + 2);
		}
		break;
	case Left:
		if (Grid_getGrid(playerX - 1, playerY) == 'p' && Grid_getGrid(playerX - 2, playerY) == ' ')
		{
			Player_BearPush(playerX - 1, playerY, playerX - 2, playerY);
		}
		break;
	case Right:
		if (Grid_getGrid(playerX + 1, playerY) == 'p' && Grid_getGrid(playerX + 2, playerY) == ' ')
		{
			Player_BearPush(playerX + 1, playerY, playerX + 2, playerY);
		}
		break;
	}
}

/* Set Position of player */
void Player_SetPosition(int x, int y)
{
	playerX = x;
	playerY = y;
	Player_PrintPlayer();
}

/* Turn back to monkey */
void Player_Unpossess()
{
	currentMode = Monkey;
	player = 'M';
	Player_PrintPlayer();
}

/* Push obstacle */
void Player_BearPush(int obstacleOldPosX, int obstacleOldPosY, int obstacleNewPosX, int obstacleNewPosY)
{
	/* Set new position of obstacle */
	Grid_setGrid(obstacleNewPosX, obstacleNewPosY, Grid_getGrid(obstacleOldPosX, obstacleOldPosY));
	/* Set old position to ' ' */
	Grid_setGrid(obstacleOldPosX, obstacleOldPosY, ' ');
}

/* Break Wall */
void Player_RhinoWallBreak(int wallPosX, int wallPosY)
{
	/* Set the wall in grid to ' ' */
	Grid_setGrid(wallPosX, wallPosY, ' ');
	/* Reduce break count and unpossess if no more break counts */
	if (--rhinoBreakCount == 0)
	{
		Player_Unpossess();
	}
}

/* Print player with specified color */
void Player_PrintPlayer()
{
	/* set Colour, set cursor, then print and reset color */
	Colours_SetColor(PLAYER_COLOUR);
	WindowsHelper_SetCursorPosition(playerX, playerY);
	printf("%c", player);
	Colours_ResetColor();
}

/* Prints current direction facing and additional debug info if enabled */
void Player_PrintInfo()
{
	WindowsHelper_SetCursorPosition(0, -1);
	if (currentDirection == Up)
	{
		printf("Direction: %5s", "Up");
	}
	else if (currentDirection == Down)
	{
		printf("Direction: %5s", "Down");
	}
	else if (currentDirection == Left)
	{
		printf("Direction: %5s", "Left");
	}
	else if (currentDirection == Right)
	{
		printf("Direction: %5s", "Right");
	}

	/* Debug Info */
	if (debug)
	{
		printf(" X: %3d  Y: %3d Rhino Break Count: %d", playerX, playerY, rhinoBreakCount);
	}
}