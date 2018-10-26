#pragma once
#include <stdio.h>
#include <windows.h>
#include "WindowsHelper.h"
#include "Grid.h"
#include "Player.h"
#include "Game.h"


int main(void)
{
	enum GameState {
		Start,
		MainMenu,
		Playing,
		Credits,
		Quit
	};

	enum GameState currentState = Playing;
	
	/*Engine Initialise*/
	WindowsHelper_Init();
	Player_InitPlayer();

	/*Initialise Game*/
	Game_InitGame(1);

	/*While loop*/
	while (currentState != Quit)
	{
		switch (currentState)
		{
			case Start:
				break;
			case MainMenu:
				break;
			case Playing:
				Game_Update();
				break;
			case Credits:
				break;
			case Quit:
				break;
		}
	}

	getchar();

	return 0;
}