#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "WindowsHelper.h"

/*Variables used to handle Windows stuff, not exposed to other parts of the game*/
HANDLE wHnd;    /* Handle to write to the console.*/
HANDLE rHnd;    /* Handle to read from the console.*/

/*Always call this function first before any other WindowsHelper functions*/
void WindowsHelper_Init()
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT(CONSOLE_TITLE));
}

/*Sets the console cursor position. Note that (0,0) is the top left of the console*/
void WindowsHelper_SetCursorPosition(int x, int y)
{
	COORD center = { x, y };
	SetConsoleCursorPosition(wHnd, center);
}

/*Wrapper to the function*/
void WindowsHelper_GetLargestConsoleWindowSize(int *width, int* height)
{
	if (width == NULL || height == NULL)
	{
		return;
	}

	COORD size = GetLargestConsoleWindowSize(wHnd);
	//Dereferncing pointers to assign integer values into the integers being pointed at
	*width = size.X;
	*height = size.Y;
}

/*Setting the window to be as big as possible*/
void WindowsHelper_FullScreen()
{
	int width = 0, height = 0;
	WindowsHelper_GetLargestConsoleWindowSize(&width, &height);

	COORD bufferSize = { width, height };
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
	SetConsoleWindowInfo(wHnd, 1, &windowSize);
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