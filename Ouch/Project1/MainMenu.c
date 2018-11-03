#include "MainMenu.h"
#include "Game.h"

/* variables here, must be static */

void MainMenu_Init()
{

}
void MainMenu_Update()
{
	/* do stuff here */

	/* change state accordingly e.g. go to play or credits */

	Game_setCurrentState(Playing);
}

/* function definitions here */