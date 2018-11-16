#pragma once

/* Forms that player can use */
enum PlayerMode {
	Monkey,
	Rhino,
	Bear
};

/* Direction that player is facing */
enum Direction {
	Up,
	Down,
	Left,
	Right
};

void Player_InitPlayer();
void Player_Controls();
void Player_Move();
void Player_Interact();
int Player_DeathCheck();
void Player_Monkey();
void Player_Rhino();
void Player_Bear();
void Player_SetPosition(int x, int y);
void Player_Unpossess();
void Player_BearPush(int obstacleOldPosX, int obstacleOldPosY, int obstacleNewPosX, int obstacleNewPosY);
void Player_RhinoWallBreak(int wallPosX, int wallPosY);
void Player_PrintPlayer();