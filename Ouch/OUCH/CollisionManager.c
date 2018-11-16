#pragma once
#include "CollisionManager.h"

/*Returns 1 if collided else 0*/
bool Collision_Check(int posX, int posY)
{
	if (Grid_getGrid(posX, posY) != '#' && /*wall*/
		Grid_getGrid(posX, posY) != 'p' && /*pushable object*/
		Grid_getGrid(posX, posY) != 'b' && /*breakable wall*/
		Grid_getGrid(posX, posY) != 'B' && /*bear enemy*/
		Grid_getGrid(posX, posY) != 'R')   /*rhino enemy*/
	{
		return 0;
	}
	else
		return 1;
}