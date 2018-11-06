#pragma once
/*Enemy class initial and final position*/
struct Enemy
{
	int posX;
	int posY;
	char direction;
	char symbol;
	char activated;
};
/*functions to set enemy positions in grid array*/
void Enemy_init(int array, int posX, int posY, char direction, char symbol);
/*moves enemy - to be updated*/
void Enemy_Update();