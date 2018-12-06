/******************************************************************************/
/*!
\file   Game.h
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for Game.c
*/
/******************************************************************************/

#pragma once

void Game_Init();
void Game_LoadLevel(int level);
void Game_Update(float dt);
void Game_LevelComplete();