#include "Player.h"
#include "WindowsHelper.h"
#include "Grid.h"
#include <windows.h>
#include <stdio.h>
#include "Colours.h"
#include "Enemy.h"

const int KEY_UP = 0x1;

/* Private variables*/
static int playerX, playerY;            /* Player Coordinates */
static int possessRange;                /* Possession Range */
static char player;                     /* Player Character */
static enum PlayerMode currentMode;     /* Current Form of the Player*/
static enum Direction currentDirection; /* Current direction that player is facing */
static int rhinoBreakCount;             /* Number of times rhino break can be used */

/*Initialise Player position*/
void Player_InitPlayer()
{
	playerX = 1;
	playerY = 1;
	possessRange = 5;
	player = 'M';
	currentMode = Monkey;
	currentDirection = Up;
	rhinoBreakCount = 0;
	Player_PrintPlayer();
}

/*Check for player input*/
void Player_Controls()
{
	Player_Move();
	Player_Interact();
}

/* Player Movement */
void Player_Move()
{
	/*Left Key Entered*/
	if ((GetAsyncKeyState(VK_LEFT) &KEY_UP) == KEY_UP)
	{
		currentDirection = Left;
		if (Grid_getGrid(playerX - 1, playerY) != '#' &&
			Grid_getGrid(playerX - 1, playerY) != 'p' &&
			Grid_getGrid(playerX - 1, playerY) != 'X')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerX--;

			Player_PrintPlayer();
		}
	}
	/*Right Key Entered*/
	else if ((GetAsyncKeyState(VK_RIGHT) &KEY_UP) == KEY_UP)
	{
		currentDirection = Right;
		if (Grid_getGrid(playerX + 1, playerY) != '#' &&
			Grid_getGrid(playerX + 1, playerY) != 'p' &&
			Grid_getGrid(playerX + 1, playerY) != 'X')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerX++;

			Player_PrintPlayer();
		}
	}
	/*Up Key Entered*/
	else if ((GetAsyncKeyState(VK_UP) &KEY_UP) == KEY_UP)
	{
		currentDirection = Up;
		if (Grid_getGrid(playerX, playerY - 1) != '#' &&
			Grid_getGrid(playerX, playerY - 1) != 'p' &&
			Grid_getGrid(playerX, playerY - 1) != 'X')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerY--;

			Player_PrintPlayer();
		}
	}
	/*Down Key Entered*/
	else if ((GetAsyncKeyState(VK_DOWN) &KEY_UP) == KEY_UP)
	{
		currentDirection = Down;
		if (Grid_getGrid(playerX, playerY + 1) != '#' &&
			Grid_getGrid(playerX, playerY + 1) != 'p' &&
			Grid_getGrid(playerX, playerY + 1) != 'X')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerY++;

			Player_PrintPlayer();
		}
	}
}

/*Interaction with objects*/
void Player_Interact()
{
	/*Spacebar Entered*/
	if ((GetAsyncKeyState(VK_SPACE) &KEY_UP) == KEY_UP)
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
	/* C Key Entered */
	else if ((GetAsyncKeyState(0x43) &KEY_UP) == KEY_UP)
	{
		switch (currentMode)
		{
			case Rhino:
			case Bear:
				Player_Unpossess();
				break;
		}
	}
}

/* Check if player collided with any enemy */
int Player_DeathCheck()
{
	if (Grid_getGrid(playerX, playerY) == 'R' || Grid_getGrid(playerX, playerY) == 'B')
	{
		return 1;
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
				if (Grid_getGrid(playerX, playerY - possessRange) == 'B' || 
					Grid_getGrid(playerX, playerY - possessRange) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX, playerY - possessRange);
					
					Enemy_Kill(playerX, playerY - possessRange);

					playerY -= possessRange;

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
				if (Grid_getGrid(playerX, playerY + possessRange) == 'B' ||
					Grid_getGrid(playerX, playerY + possessRange) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX, playerY + possessRange);

					Enemy_Kill(playerX, playerY + possessRange);

					playerY += possessRange;

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
				if (Grid_getGrid(playerX - possessRange, playerY) == 'B' ||
					Grid_getGrid(playerX - possessRange, playerY) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX - possessRange, playerY);

					Enemy_Kill(playerX - possessRange, playerY);

					playerX -= possessRange;

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
				if (Grid_getGrid(playerX + possessRange, playerY) == 'B' ||
					Grid_getGrid(playerX + possessRange, playerY) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX + possessRange, playerY);

					Enemy_Kill(playerX + possessRange, playerY);

					playerX += possessRange;

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
void Player_Rhino()
{
	switch (currentDirection)
	{
	case Up:
		if (Grid_getGrid(playerX, playerY - 1) == 'X')
		{
			Player_RhinoWallBreak(playerX, playerY - 1);
		}
		break;
	case Down:
		if (Grid_getGrid(playerX, playerY + 1) == 'X')
		{
			Player_RhinoWallBreak(playerX, playerY + 1);
		}
		break;
	case Left:
		if (Grid_getGrid(playerX - 1, playerY) == 'X')
		{
			Player_RhinoWallBreak(playerX - 1, playerY);
		}
		break;
	case Right:
		if (Grid_getGrid(playerX + 1, playerY) == 'X')
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
	WindowsHelper_SetCursorPosition(playerX, playerY);
	printf("%c", player);
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
	Grid_setGrid(obstacleNewPosX, obstacleNewPosY, Grid_getGrid(obstacleOldPosX, obstacleOldPosY));
	Grid_setGrid(obstacleOldPosX, obstacleOldPosY, ' ');
	WindowsHelper_SetCursorPosition(obstacleNewPosX, obstacleNewPosY);
	printf("%c", Grid_getGrid(obstacleNewPosX, obstacleNewPosY));
	WindowsHelper_SetCursorPosition(obstacleOldPosX, obstacleOldPosY);
	printf("%c", Grid_getGrid(obstacleOldPosX, obstacleOldPosY));
}

/* Break Wall */
void Player_RhinoWallBreak(int wallPosX, int wallPosY)
{
	Grid_setGrid(wallPosX, wallPosY, ' ');
	WindowsHelper_SetCursorPosition(wallPosX, wallPosY);
	printf("%c", Grid_getGrid(wallPosX, wallPosY));
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