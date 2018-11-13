#include "Switch.h"
#include "Grid.h"

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
			button[i].Pressed = 0;
			Grid_setGrid(posX, posY, button[i].symbol);
			button[i].activated = 1;
		}
	}
	return;
}
void Button_Pressed(int posX, int posY) {
	for (i = 0; i < 50; i++) {
		if(button[i].posX==posX) {
			if (button[i].posY==posY) {
				button[i].Pressed = 1;
			}
		}
	}
}