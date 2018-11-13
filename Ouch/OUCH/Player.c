#include "Player.h"
#include "WindowsHelper.h"
#include "Grid.h"
#include <windows.h>
#include <stdio.h>
#include "Enemy.h"

const int KEY_UP = 0x1;

/* Private variables*/
static int playerX, playerY;            /* Player Coordinates */
static int possessRange;                /* Possession Range */
static char player;                     /* Player Character */
static enum PlayerMode currentMode;     /* Current Form of the Player*/
static enum Direction currentDirection; /* Current direction that player is facing */

/*Initialise Player position*/
void Player_InitPlayer()
{
	playerX = 1;
	playerY = 1;
	possessRange = 5;
	player = 'M';
	currentMode = Monkey;
	currentDirection = Up;
	WindowsHelper_SetCursorPosition(playerX, playerY);
	printf("%c", player);
}

/*Check for player input*/
void Player_Controls()
{
	Player_Move();
	Player_Interact();
}

/*Move player*/
void Player_Move()
{
	/*Left Key Entered*/
	if ((GetAsyncKeyState(VK_LEFT) &KEY_UP) == KEY_UP)
	{
		currentDirection = Left;
		if (Grid_getGrid(playerX - 1, playerY) != '#' &&
			Grid_getGrid(playerX - 1, playerY) != 'p')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerX--;

			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", player);
		}
	}
	/*Right Key Entered*/
	else if ((GetAsyncKeyState(VK_RIGHT) &KEY_UP) == KEY_UP)
	{
		currentDirection = Right;
		if (Grid_getGrid(playerX + 1, playerY) != '#' &&
			Grid_getGrid(playerX + 1, playerY) != 'p')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerX++;

			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", player);
		}
	}
	/*Up Key Entered*/
	else if ((GetAsyncKeyState(VK_UP) &KEY_UP) == KEY_UP)
	{
		currentDirection = Up;
		if (Grid_getGrid(playerX, playerY - 1) != '#' &&
			Grid_getGrid(playerX, playerY - 1) != 'p')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerY--;

			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", player);
		}
	}
	/*Down Key Entered*/
	else if ((GetAsyncKeyState(VK_DOWN) &KEY_UP) == KEY_UP)
	{
		currentDirection = Down;
		if (Grid_getGrid(playerX, playerY + 1) != '#' &&
			Grid_getGrid(playerX, playerY + 1) != 'p')
		{
			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", Grid_getGrid(playerX, playerY));

			playerY++;

			WindowsHelper_SetCursorPosition(playerX, playerY);
			printf("%c", player);
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
				if (Grid_getGrid(playerX,playerY - possessRange) == 'B' || 
					Grid_getGrid(playerX, playerY - possessRange) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX, playerY - possessRange);
					
					Enemy_Kill(playerX, playerY - possessRange);

					playerY -= possessRange;

					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", player);
					
					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
					}
					break;
				}
			}
			break;
		case Down:
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				if (Grid_getGrid(playerX, playerY + possessRange) == 'B' ||
					Grid_getGrid(playerX, playerY + possessRange) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX, playerY + possessRange);

					Enemy_Kill(playerX, playerY + possessRange);

					playerY += possessRange;

					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", player);

					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
					}
					break;
				}
			}
			break;
		case Left:
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				if (Grid_getGrid(playerX - possessRange, playerY) == 'B' ||
					Grid_getGrid(playerX - possessRange, playerY) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX - possessRange, playerY);

					Enemy_Kill(playerX - possessRange, playerY);

					playerX -= possessRange;

					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", player);

					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
					}
					break;
				}
			}
			break;
		case Right:
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				if (Grid_getGrid(playerX + possessRange, playerY) == 'B' ||
					Grid_getGrid(playerX + possessRange, playerY) == 'R')
				{
					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", Grid_getGrid(playerX, playerY));
					player = Grid_getGrid(playerX + possessRange, playerY);

					Enemy_Kill(playerX + possessRange, playerY);

					playerX += possessRange;

					WindowsHelper_SetCursorPosition(playerX, playerY);
					printf("%c", player);

					if (player == 'B')
					{
						currentMode = Bear;
					}
					else
					{
						currentMode = Rhino;
					}
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
		break;
	case Down:
		break;
	case Left:
		break;
	case Right:
		break;
	}
}

void Player_Bear()
{
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

void Player_SetPosition(int x, int y)
{
	playerX = x;
	playerY = y;
	WindowsHelper_SetCursorPosition(playerX, playerY);
	printf("%c", player);
}

void Player_Unpossess()
{
	currentMode = Monkey;
	player = 'M';
	WindowsHelper_SetCursorPosition(playerX, playerY);
	printf("%c", player);
}

void Player_BearPush(int obstacleOldPosX, int obstacleOldPosY, int obstacleNewPosX, int obstacleNewPosY)
{
	Grid_setGrid(obstacleNewPosX, obstacleNewPosY, Grid_getGrid(obstacleOldPosX, obstacleOldPosY));
	Grid_setGrid(obstacleOldPosX, obstacleOldPosY, ' ');
	WindowsHelper_SetCursorPosition(obstacleNewPosX, obstacleNewPosY);
	printf("%c", Grid_getGrid(obstacleNewPosX, obstacleNewPosY));
	WindowsHelper_SetCursorPosition(obstacleOldPosX, obstacleOldPosY);
	printf("%c", Grid_getGrid(obstacleOldPosX, obstacleOldPosY));
}

void Player_RhinoWallBreak(int wallPosX, int wallPosY)
{

}