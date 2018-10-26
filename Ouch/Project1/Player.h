#ifndef PLAYER_H
#define PLAYER_H
#include "WindowsHelper.h"
#include "Grid.h"
#include <windows.h>
#include <stdio.h>

int playerX, playerY, possessRange;
char player;
char direction;

void Player_InitPlayer();
void Player_Controls();
void Player_move();
void Player_Interact();

#endif