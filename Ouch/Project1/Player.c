#include "Player.h"
/*Player controls file*/
const KEY_UP = 0x1;

/*Initialise Player position*/
void Player_InitPlayer()
{
	playerX = 0;
	playerY = 0;
	player = 'M';
	WindowsHelper_SetCursorPosition(playerX, playerY);
	printf("%c", player);
}

/*Move player*/
void Player_move()
{
	if (GetAsyncKeyState(VK_LEFT) &KEY_UP == KEY_UP)
	{
		printf("%c", Grid_getGrid(playerX, playerY));
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerX--;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}
	else if (GetAsyncKeyState(VK_RIGHT) &KEY_UP == KEY_UP)
	{
		printf("%c", Grid_getGrid(playerX, playerY));
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerX++;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}
	else if (GetAsyncKeyState(VK_UP) &KEY_UP == KEY_UP)
	{
		printf("%c", Grid_getGrid(playerX, playerY));
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerY--;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}
	else if (GetAsyncKeyState(VK_DOWN) &KEY_UP == KEY_UP)
	{
		printf("%c", Grid_getGrid(playerX, playerY));
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerY++;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}
}