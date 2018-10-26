#pragma once
//Set the Desired Console title here
#define CONSOLE_TITLE "OUCH!"

void WindowsHelper_Init();
void WindowsHelper_SetCursorPosition(int x, int y);
void WindowsHelper_FullScreen();
int WindowsHelper_GetConsoleWidth();
int WindowsHelper_GetConsoleHeight();

void WindowsHelper_ClearScreen();