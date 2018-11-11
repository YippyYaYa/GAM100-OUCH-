#pragma once

enum PlayerMode {
	Monkey,
	Rhino,
	Bear
};

enum Direction {
	Up,
	Down,
	Left,
	Right
};

void Player_InitPlayer();
void Player_Controls();
void Player_move();
void Player_Interact();
int Player_DeathCheck();
void Player_Monkey();
void Player_Rhino();
void Player_Bear();
void Player_SetPosition(int x, int y);
void Player_Unpossess();