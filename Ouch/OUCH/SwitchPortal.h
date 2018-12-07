/******************************************************************************/
/*!
\file   SwitchPortal.h
\author Chew Wei Fa Alex , Ho Jun Hao
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for SwitchPortal.c which was scrapped
*/
/******************************************************************************/
#pragma once
#include <stdbool.h>
#include "WindowsHelper.h"
#include "Grid.h"
#include "Player.h"
#define OBJECT_ARRAY_SIZE 50

/*Enemy class initial and final position*/
struct Object
{
	/*Switch position and symbol, and if the switch is pressed - default is not pressed 0*/
	int SwitchPosX;
	int SwitchPosY;
	unsigned char SwitchSymbol;
	bool Pressed;
	/*Portal Starting position and ending position and symbol*/
	int StartPortalX;
	int StartPortalY;
	int EndPortalX;
	int EndPortalY;
	unsigned char PortalPressedSymbol;
	unsigned char PortalUnpressedSymbol;
	/*is the object spawned*/
	bool activated;
};
void SwitchPortal_Init();
void SwitchPortal_Spawn(int SwitchPosX, int SwitchPosY, int StartPortalX, int StartPortalY, int EndPortalX, int EndPortalY);
void SwitchPortal_Interact(int posX, int posY);