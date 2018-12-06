/******************************************************************************/
/*!
\file   Grid.h
\author Chew Wei Fa Alex
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for Grid.c
*/
/******************************************************************************/
#pragma once
#include <stdio.h>
#include "Enemy.h"
#include "WindowsHelper.h"
#include "GameStateManager.h"

void Grid_initGrid(int file);
void Grid_printGrid();
unsigned char Grid_getGrid(int posX, int posY);
void Grid_setGrid(int posX, int posY, unsigned char symbol);
unsigned char Ascii(unsigned char i);