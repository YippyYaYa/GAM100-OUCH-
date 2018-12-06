/******************************************************************************/
/*!
\file   Colours.h
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file is contains function declarations for Colours.c
*/
/******************************************************************************/

#pragma once
#include <windows.h>

/* All colour definitions goes here */
#define PLAYER_COLOUR 6  /* Brown */
#define ENEMY_COLOUR 12  /* LIGHT RED */
#define RED 4            /* Loading Screen */
#define PUSHABLE 3       /* Pushable Objects */
#define DESTROYABLE 11   /* Destroyable objects */
#define END 2            /* Level Exit Portal */
#define GAMEOVER 3       /* Gameover screen */

void Colours_Init();
void Colours_SetColor(WORD newColor);
void Colours_ResetColor();