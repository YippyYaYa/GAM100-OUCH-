/******************************************************************************/
/*!
\file   Loading.h
\author Toh Gim Hsiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function declarations for Loading.c
*/
/******************************************************************************/


#pragma once
/* function declaration here */
void Loading_Init();
void Loading_Update(float dt);
void DebugMessage(int index);
void DebugMessagewithPosition(int index, int posX, int posY);