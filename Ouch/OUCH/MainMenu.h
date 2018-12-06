/******************************************************************************/
/*!
\file   MainMenu.h
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for MainMenu.c
*/
/******************************************************************************/

#pragma once

enum Selected {
	MenuPlay,
	MenuQuit,
	MenuCredits
};

void MainMenu_Init();
void MainMenu_Update();

/* function declaration here */