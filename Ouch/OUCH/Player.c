#include "Player.h"
#include "WindowsHelper.h"
#include "Grid.h"
#include <windows.h>
#include <stdio.h>
#include "Enemy.h"
/*Player controls file*/
const int KEY_UP = 0x1;

/* Private variables*/
static int playerX, playerY, possessRange;
static char player;
static enum PlayerMode currentMode;
static enum Direction currentDirection;

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
	Player_move();
	Player_Interact();
}

/*Move player*/
void Player_move()
{
	/*Left Key Entered*/
	if ((GetAsyncKeyState(VK_LEFT) &KEY_UP) == KEY_UP && Grid_getGrid(playerX-1, playerY) != '#')
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));

		playerX--;

		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);

		currentDirection = Left;
	} 
	/*Right Key Entered*/
	else if ((GetAsyncKeyState(VK_RIGHT) &KEY_UP) == KEY_UP && Grid_getGrid(playerX+1, playerY) != '#')
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));

		playerX++;

		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);

		currentDirection = Right;
	}
	/*Up Key Entered*/
	else if ((GetAsyncKeyState(VK_UP) &KEY_UP) == KEY_UP && Grid_getGrid(playerX, playerY-1) != '#')
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));

		playerY--;

		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);

		currentDirection = Up;
	}
	/*Down Key Entered*/
	else if ((GetAsyncKeyState(VK_DOWN) &KEY_UP) == KEY_UP && Grid_getGrid(playerX, playerY+1) != '#')
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));

		playerY++;

		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);

		currentDirection = Down;
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
				break;
			case Rhino:
				break;
		}
	}
}

int Player_DeathCheck()
{
	if (Grid_getGrid(playerX, playerY) == 'R' || Grid_getGrid(playerX, playerY) == 'B')
	{
		return 1;
	}
	return 0;
}

void Player_Monkey()
{
	switch (currentDirection)
	{
		case Up:
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				if (Grid_getGrid(playerX,playerY - possessRange) != ' ')
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

					//printf("HIT\n");
					break;
				}
				else
				{
					//printf("NO HIT\n");
				}
			}
			break;
		case Down:
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				if (Grid_getGrid(playerX, playerY + possessRange) != ' ')
				{
					printf("HIT\n");
					break;
				}
				else
				{
					printf("NO HIT\n");
				}
			}
			break;
		case Left:
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				if (Grid_getGrid(playerX - possessRange, playerY) != ' ')
				{
					printf("HIT\n");
					break;
				}
				else
				{
					printf("NO HIT\n");
				}
			}
			break;
		case Right:
			for (possessRange = 1; possessRange <= 5; possessRange++)
			{
				if (Grid_getGrid(playerX + possessRange, playerY ) != ' ')
				{
					printf("HIT\n");
					break;
				}
				else
				{
					printf("NO HIT\n");
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
		break;
	case Down:
		break;
	case Left:
		break;
	case Right:
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