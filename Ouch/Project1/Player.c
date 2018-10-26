#include "Player.h"
/*Player controls file*/
const KEY_UP = 0x1;

/*Initialise Player position*/
void Player_InitPlayer()
{
	playerX = 0;
	playerY = 0;
	possessRange = 5;
	player = 'M';
	direction = 'U';
}

void Player_Controls()
{
	Player_move();
	Player_Interact();
}

/*Move player*/
void Player_move()
{
	/*Left Key Entered*/
	if ((GetAsyncKeyState(VK_LEFT) &KEY_UP) == KEY_UP)
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerX--;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	} /*Right Key Entered*/
	else if ((GetAsyncKeyState(VK_RIGHT) &KEY_UP) == KEY_UP)
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerX++;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}/*Up Key Entered*/
	else if ((GetAsyncKeyState(VK_UP) &KEY_UP) == KEY_UP)
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerY--;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}/*Down Key Entered*/
	else if ((GetAsyncKeyState(VK_DOWN) &KEY_UP) == KEY_UP)
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerY++;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}
}

void Player_Interact()
{
	/*Spacebar Entered*/
	if ((GetAsyncKeyState(VK_SPACE) &KEY_UP) == KEY_UP)
	{
		/*Possession Check*/
		if (player == 'M')
		{
			switch (direction)
			{
				case 'U':
					for (possessRange = 1; possessRange <= 5; possessRange++)
					{
						if (Grid_getGrid(playerX,playerY + possessRange) != ' ' && Grid_getGrid(playerX, playerY + possessRange) != '#')
						{
							printf("HIT\n");
						}
						else
						{
							printf("NO HIT\n");
						}
					}
					break;
				case 'D':
					break;
				case 'L':
					break;
				case 'R':
					break;
			}
		}
		else
		{
			return;
		}
	}
}
