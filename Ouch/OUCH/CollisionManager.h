#pragma once
#include "Grid.h"
#include <stdbool.h>
/*returns 1 if collided, else 0*/
bool Collision_Check(int posX, int posY);
bool Collision_Enemy(int posX, int posY);