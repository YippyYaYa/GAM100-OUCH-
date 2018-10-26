#pragma once
#include <stdio.h>
#include <windows.h>
#include "WindowsHelper.h"
#include "Grid.h"
#include "Player.h"
#include "Game.h"


int main(void)
{
	/*Engine Initialise*/
	/* Initialise Console grid*/
	WindowsHelper_Init();

	/*Initialise Game*/
	Game_InitGame();

	Game_setCurrentState(Playing);

	while (Game_getCurrentState() != Quit)
	{
		Game_Update();
	}

	return 0;
}