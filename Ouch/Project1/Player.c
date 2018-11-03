#include "Player.h"
/*Player controls file*/
const int KEY_UP = 0x1;

/* Private variables*/
static int playerX, playerY, possessRange;
static char player;
static char direction;

enum PlayerMode {
	Monkey,
	Rhino,
	Bear
};


/*Initialise Player position*/
void Player_InitPlayer()
{
	playerX = 1;
	playerY = 1;
	possessRange = 5;
	player = 'M';
	direction = 'U';
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
	} /*Right Key Entered*/
	else if ((GetAsyncKeyState(VK_RIGHT) &KEY_UP) == KEY_UP && Grid_getGrid(playerX+1, playerY) != '#')
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerX++;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}/*Up Key Entered*/
	else if ((GetAsyncKeyState(VK_UP) &KEY_UP) == KEY_UP && Grid_getGrid(playerX, playerY-1) != '#')
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerY--;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}/*Down Key Entered*/
	else if ((GetAsyncKeyState(VK_DOWN) &KEY_UP) == KEY_UP && Grid_getGrid(playerX, playerY+1) != '#')
	{
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", Grid_getGrid(playerX, playerY));
		playerY++;
		WindowsHelper_SetCursorPosition(playerX, playerY);
		printf("%c", player);
	}
}

/*Interaction with objects*/
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
						if (Grid_getGrid(playerX,playerY - possessRange) != ' ')
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