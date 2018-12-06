/******************************************************************************/
/*!
\file   WindowsHelper.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the functions dealing with the console 
*/
/******************************************************************************/

#include <Windows.h>
#include <stdio.h>
#include "WindowsHelper.h"

HANDLE wHnd;    /* Handle to write to the console.*/
HANDLE rHnd;    /* Handle to read from the console.*/

static short width = 102; /* width of console size*/
static short height = 27; /* height of console size*/

void WindowsHelper_Init()
{
	COORD bufferSize;
	bufferSize.X = width;
	bufferSize.Y = height;

	SMALL_RECT windowSize;
	windowSize.Left = 0;
	windowSize.Top = 0;
	windowSize.Right = width - 1;
	windowSize.Bottom = height - 1;

	CONSOLE_CURSOR_INFO cursorInfo;
	DWORD consoleMode;

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT(CONSOLE_TITLE));

	/* Set Console size */
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, 1, &windowSize);
	
	/* Hide blinking cursor */
	GetConsoleCursorInfo(wHnd, &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(wHnd, &cursorInfo);

	/* Disable extra row printing at the end of screen */
	GetConsoleMode(wHnd, &consoleMode);
	consoleMode |= DISABLE_NEWLINE_AUTO_RETURN | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(wHnd, consoleMode);
}

/*Sets the console cursor position. */
void WindowsHelper_SetCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = (short)x + 1;
	pos.Y = (short)y + 1;
	SetConsoleCursorPosition(wHnd, pos);
}