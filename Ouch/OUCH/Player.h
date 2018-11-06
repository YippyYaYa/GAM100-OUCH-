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