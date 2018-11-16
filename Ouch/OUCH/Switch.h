#pragma once
#include <stdbool.h>
/*Enemy class initial and final position*/
struct Button
{
	int posX;
	int posY;
	char symbol;
	int PortalX;
	int PortalY;
	bool Pressed;
	bool activated;
};
void Button_Init();
void Button_Spawn(int posX, int posY, int PortalX, int PortalY);
void Button_Pressed(int posX, int posY);