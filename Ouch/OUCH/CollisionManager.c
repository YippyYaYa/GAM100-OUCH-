#pragma once
#include "CollisionManager.h"

/*Returns 1 if collided else 0*/
bool Collision_Check(int posX, int posY)
{
	if (Grid_getGrid(posX, posY) != '#' && /*wall*/
		Grid_getGrid(posX, posY) != 'p' && /*pushable object*/
		Grid_getGrid(posX, posY) != 'b')   /*breakable wall*/
	{
		return 0;
	}
	else
		return 1;
}