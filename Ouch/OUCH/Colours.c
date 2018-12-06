/******************************************************************************/
/*!
\file   Colours.c
\author Chong Yi Fang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file is in charge of changing and resetting of text colours before printing
*/
/******************************************************************************/

#include "Colours.h" /* Function declarations */
#include <Windows.h> /* Console output handle, set text attribute */

static HANDLE outputConsole;                   /* Store handle to output window*/
static CONSOLE_SCREEN_BUFFER_INFO consoleInfo; /* Store console buffer info */
static WORD resetAttributes;                   /* Store default attributes */

/* Initialise variables at start of program */
void Colours_Init()
{
	outputConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(outputConsole, &consoleInfo);
	/* Store original colours for resetting */
	resetAttributes = consoleInfo.wAttributes;
}

/* Set to colour in parameter, define all colours usage in .h */
void Colours_SetColor(WORD newColor)
{
	SetConsoleTextAttribute(outputConsole, newColor);
}

/* Reset colour to default */
void Colours_ResetColor()
{
	SetConsoleTextAttribute(outputConsole, resetAttributes);
}