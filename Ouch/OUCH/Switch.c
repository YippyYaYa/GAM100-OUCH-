#include "Switch.h"
#include "Grid.h"
#define OBJECT_ARRAY_SIZE 50

struct Button button[OBJECT_ARRAY_SIZE];
static int i;

void Button_Init()
{
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++)
		button[i].activated = 0;
}

void Button_Spawn(int posX, int posY, int PortalX, int PortalY) {
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++){
		if (button[i].activated == 0) {
			button[i].posX = posX;
			button[i].posY = posY;
			button[i].PortalX = PortalX;
			button[i].PortalY = PortalY;
			button[i].symbol = 233;
			button[i].Pressed = 0;
			Grid_setGrid(posX, posY, button[i].symbol);
			button[i].activated = 1;
		}
	}
	return;
}
void Button_Pressed(int posX, int posY) {
	for (i = 0; i < OBJECT_ARRAY_SIZE; i++) {
		if(button[i].posX==posX) {
			if (button[i].posY==posY) {
				button[i].Pressed = 1;
			}
		}
	}
}