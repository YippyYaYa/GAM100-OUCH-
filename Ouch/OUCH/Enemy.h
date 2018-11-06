#pragma once
/*Enemy class initial and final position*/
struct Enemy
{
	float posX;
	float posY;
	char direction;
	char symbol;
	float velocity;
	char activated;
	char oldGrid;
};
/*functions to set enemy positions in grid array*/
void Enemy_Init(int array, float posX, float posY, char direction, char symbol, float velocity);
/*moves enemy - to be updated*/
void Enemy_Update(float dt);