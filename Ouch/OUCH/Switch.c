#include "Switch.h"
#include "Grid.h"
#include <stdio.h>

struct Button button[50];
static int i;

void Button_Init(int posX, int posY, int PortalX, int PortalY) {
	for (i = 0; i < 50; i++){
		if (button[i].activated == 0) {
			button[i].posX = posX;
			button[i].posY = posY;
			button[i].PortalX = PortalX;
			button[i].PortalY = PortalY;
			button[i].symbol = 233;
			button[i].State = 0;
			Grid_setGrid(posX, posY, button[i].symbol))
			button[i].activated = 1;
		}
	}
	return;
}
void Button_Pressed(float posX, float posY, float PortalX, float PortalY);