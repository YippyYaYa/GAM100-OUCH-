#pragma once
#include "CollisionManager.h"

/*Collision check for unwalkable objects - Returns 1 if collided, else 0*/
bool Collision_Check(int posX, int posY)
{
	if (Grid_getGrid(posX, posY) != '#' && /*wall*/
		Grid_getGrid(posX, posY) != 'p' && /*pushable object*/
		Grid_getGrid(posX, posY) != 'd')   /*breakable wall*/
	{
		return 0;
	}
	else
		return 1;
}
/*Collision check for enemies - Returns 1 if collided with enemy, else 0*/
bool Collision_Enemy(int posX, int posY)
{
	if (Grid_getGrid(posX, posY) != 'B' && /*Bear enemy*/
		Grid_getGrid(posX, posY) != 'R')   /*Rhino enemy*/
	{
		return 0;
	}
	else
		return 1;
}