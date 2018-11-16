#pragma once
#include "SwitchPortal.h"
#include "Colours.h"

static struct Object objects[OBJECT_ARRAY_SIZE];
static int i;

/*Init Switch and portals*/
void SwitchPortal_Init()
{
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++)
	{
		objects[i].activated = 0;
		objects[i].Pressed = 0;
		objects[i].SwitchSymbol = 233;
		objects[i].PortalPressedSymbol = 178;
		objects[i].PortalUnpressedSymbol = 176;
	}
}
/*Spawns switch and portal - swtich position, portal start position, portal end position*/
void SwitchPortal_Spawn(int SwitchPosX, int SwitchPosY, int StartPortalX,
						int StartPortalY, int EndPortalX, int EndPortalY)
{
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++)
	{
		if (objects[i].activated == 0)
		{
			/*Set Switch Position*/
			objects[i].SwitchPosX = SwitchPosX;
			objects[i].SwitchPosY = SwitchPosY;
			Grid_setGrid(objects[i].SwitchPosX, objects[i].SwitchPosY, objects[i].SwitchSymbol);
			/*Set Portal Start Position*/
			objects[i].StartPortalX = StartPortalX;
			objects[i].StartPortalY = StartPortalY;
			Grid_setGrid(objects[i].StartPortalX, objects[i].StartPortalY, objects[i].PortalUnpressedSymbol);
			/*Set Portal End Position*/
			objects[i].EndPortalX = EndPortalX;
			objects[i].EndPortalY = EndPortalY;
			Grid_setGrid(objects[i].EndPortalX, objects[i].EndPortalY, objects[i].PortalUnpressedSymbol);
			/*Set portal to activated*/
			objects[i].activated = 1;
		}
	}
}
/*If player is on top of portal/switch*/
void SwitchPortal_Interact(int posX, int posY)
{
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++)
	{
		if (objects[i].SwitchPosX == posX &&
			objects[i].SwitchPosY == posY &&
			objects[i].Pressed == 0)
		{
			objects[i].Pressed = 1;
			Grid_setGrid(objects[i].StartPortalX, objects[i].StartPortalY, objects[i].PortalPressedSymbol);
			Grid_setGrid(objects[i].EndPortalX, objects[i].EndPortalY, objects[i].PortalPressedSymbol);
		}
		else if (objects[i].StartPortalX == posX &&
				 objects[i].StartPortalY == posY &&
				 objects[i].Pressed == 1)
		{
			Player_SetPosition(objects[i].EndPortalX, objects[i].EndPortalY);
		}
		else if (objects[i].EndPortalX == posX &&
				 objects[i].EndPortalY == posY &&
				 objects[i].Pressed == 1)
		{
			Player_SetPosition(objects[i].StartPortalX, objects[i].StartPortalY);
		}
	}
}