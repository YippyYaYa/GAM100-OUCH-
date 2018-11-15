#include <Windows.h>
#include <stdio.h>
#include "WindowsHelper.h"

HANDLE wHnd;    /* Handle to write to the console.*/
HANDLE rHnd;    /* Handle to read from the console.*/

static short width = 100; /* width of console size*/
static short height = 25; /* height of console size*/

void WindowsHelper_Init()
{
	COORD bufferSize = { width + 1, height + 1 };
	SMALL_RECT windowSize = { 0,0, width - 1, height - 1};
	CONSOLE_CURSOR_INFO cursorInfo;
	/*DWORD consoleMode;*/

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT(CONSOLE_TITLE));

	/* Set Console size */
	SetConsoleWindowInfo(wHnd, 1, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	
	/* Hide blinking cursor */
	GetConsoleCursorInfo(wHnd, &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(wHnd, &cursorInfo);

	/* Disable extra row printing at the end of screen */
	/*
	GetConsoleMode(wHnd, &consoleMode);
	consoleMode |= DISABLE_NEWLINE_AUTO_RETURN | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(wHnd, consoleMode);*/
}

/*Sets the console cursor position. Note that (0,0) is the top left of the console*/
void WindowsHelper_SetCursorPosition(int x, int y)
{
	COORD pos = { (short)x, (short)y };
	SetConsoleCursorPosition(wHnd, pos);
}