#include <windows.h>
#include <stdio.h>
#include "WindowsHelper.h"

/*Variables used to handle Windows stuff, not exposed to other parts of the game*/
HANDLE wHnd;    /* Handle to write to the console.*/
HANDLE rHnd;    /* Handle to read from the console.*/

static short width = 100; /* width of console size*/
static short height = 25; /* height of console size*/

/*Always call this function first before any other WindowsHelper functions*/
void WindowsHelper_Init()
{
	COORD bufferSize = { width, height };
	SMALL_RECT windowSize = { 0, 0, width-1 , height-1  };
	CONSOLE_CURSOR_INFO cursorInfo;

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT(CONSOLE_TITLE));

	/* Set Console size */

	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	ShowWindow(GetConsoleWindow(), SW_SHOWNORMAL);
	
	/* Hide blinking cursor */
	GetConsoleCursorInfo(wHnd, &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(wHnd, &cursorInfo);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	printf("columns: %d\n", columns);
	printf("rows: %d\n", rows);

	CONSOLE_SCREEN_BUFFER_INFO sbInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbInfo);
	int availableColumns = sbInfo.dwSize.X;
	int availableRows = sbInfo.dwSize.Y;
	printf("available col: %d\n", availableColumns);
	printf("available row: %d\n", availableRows);
}

/*Sets the console cursor position. Note that (0,0) is the top left of the console*/
void WindowsHelper_SetCursorPosition(int x, int y)
{
	COORD center = { (short)x, (short)y };
	SetConsoleCursorPosition(wHnd, center);
}