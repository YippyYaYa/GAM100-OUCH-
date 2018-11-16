#include "SwitchPortal.h"
#include "WindowsHelper.h"
#include "Grid.h"
#define OBJECT_ARRAY_SIZE 50

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
void SwitchPortal_Spawn(int SwitchPosX, int SwitchPosY, int StartPortalX, int StartPortalY, int EndPortalX, int EndPortalY) {
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++){
		if (objects[i].activated == 0) {
			/*Set Switch Position*/
			objects[i].posX = SwitchPosX;
			objects[i].posY = SwitchPosY;
			Grid_setGrid(objects[i].posX, objects[i].posY, objects[i].SwitchSymbol);
			/*Set Portal Start Position*/
			objects[i].StartPortalX = StartPortalX;
			objects[i].StartPortalY = StartPortalY;
			Grid_setGrid(objects[i].StartPortalX, objects[i].StartPortalY, objects[i].PortalUnpressedSymbol);
			/*Set Portal End Position*/
			objects[i].EndPortalX = EndPortalX;
			objects[i].EndPortalY = EndPortalY;
			Grid_setGrid(objects[i].EndPortalX, objects[i].EndPortalY, objects[i].PortalUnpressedSymbol);
			objects[i].activated = 1;
		}
	}
	return;
}
void Switch_Pressed(int posX, int posY) {
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++) {
		if(objects[i].posX == posX) {
			if (objects[i].posY == posY) {
				objects[i].Pressed = 1;
				Grid_setGrid(objects[i].StartPortalX, objects[i].StartPortalY, objects[i].PortalPressedSymbol);
				WindowsHelper_SetCursorPosition(objects[i].StartPortalX, objects[i].StartPortalY);
				printf("%c", objects[i].PortalPressedSymbol);
				Grid_setGrid(objects[i].EndPortalX, objects[i].EndPortalY, objects[i].PortalPressedSymbol);
				WindowsHelper_SetCursorPosition(objects[i].EndPortalX, objects[i].EndPortalY);
				printf("%c", objects[i].PortalPressedSymbol);
			}
		}
	}
}