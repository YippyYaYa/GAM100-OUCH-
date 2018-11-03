#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "WindowsHelper.h"

/*Variables used to handle Windows stuff, not exposed to other parts of the game*/
HANDLE wHnd;    /* Handle to write to the console.*/
HANDLE rHnd;    /* Handle to read from the console.*/

static short width = 101; /* width of console size*/
static short height = 40; /* height of console size*/

/*Always call this function first before any other WindowsHelper functions*/
void WindowsHelper_Init()
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT(CONSOLE_TITLE));

	COORD bufferSize = { width, height };
	SMALL_RECT windowSize = { 0, 0, width-1, height-1 };

	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);	   
}

/*Sets the console cursor position. Note that (0,0) is the top left of the console*/
void WindowsHelper_SetCursorPosition(int x, int y)
{
	COORD center = { (short)x, (short)y };
	SetConsoleCursorPosition(wHnd, center);
}

/*Clears everything in the console window and sets the cursor to position (0,0)*/
void WindowsHelper_ClearScreen()
{
	system("cls");
}

int WindowsHelper_GetConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(wHnd, &csbi);
	return csbi.dwSize.X;
}

int WindowsHelper_GetConsoleHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(wHnd, &csbi);
	return csbi.dwSize.Y;
}