/******************************************************************************/
/*!
\file   CollisionManager.h
\author Chew Wei Fa Alex
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for CollisionManager.c
*/
/******************************************************************************/
#pragma once
#include "Grid.h"
#include <stdbool.h>
/*returns 1 if collided, else 0*/
bool Collision_Check(int posX, int posY);
bool Collision_Enemy(int posX, int posY);