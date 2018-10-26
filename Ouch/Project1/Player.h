#ifndef PLAYER_H
#define PLAYER_H
#include "WindowsHelper.h"
#include "Grid.h"
#include <windows.h>
#include <stdio.h>

int playerX, playerY;
char player;

void Player_InitPlayer();
void PLayer_move();

#endif