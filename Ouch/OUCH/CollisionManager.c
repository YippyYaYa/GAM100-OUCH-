#pragma once
#include "CollisionManager.h"

/*Returns 1 if collided else 0*/
bool Collision_Check(int posX, int posY)
{
	if (Grid_getGrid(posX, posY) != '#' &&
		Grid_getGrid(posX, posY) != 'p' &&
		Grid_getGrid(posX, posY) != 'X')
	{
		return 0;
	}
	else
		return 1;
}