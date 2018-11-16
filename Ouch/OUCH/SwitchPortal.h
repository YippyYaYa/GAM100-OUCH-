#pragma once
#include <stdbool.h>
#include "WindowsHelper.h"
#include "Grid.h"
#define OBJECT_ARRAY_SIZE 50

/*Enemy class initial and final position*/
struct Object
{
	/*Switch position and symbol, and if the switch is pressed - default is not pressed 0*/
	int posX;
	int posY;
	char SwitchSymbol;
	bool Pressed;
	/*Portal Starting position and ending position and symbol*/
	int StartPortalX;
	int StartPortalY;
	int EndPortalX;
	int EndPortalY;
	char PortalPressedSymbol;
	char PortalUnpressedSymbol;
	/*is the object spawned*/
	bool activated;
};
void SwitchPortal_Init();
void SwitchPortal_Spawn(int SwitchPosX, int SwitchPosY, int StartPortalX, int StartPortalY, int EndPortalX, int EndPortalY);
void Switch_Pressed(int posX, int posY);