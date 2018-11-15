#include "Colours.h"
#include <Windows.h>

static HANDLE outputConsole;                   /* Store handle to output window*/
static CONSOLE_SCREEN_BUFFER_INFO consoleInfo; /* Store console buffer info */
static WORD resetAttributes;                   /* Store default attributes */

/* Initialise variables */
void Colours_Init()
{
	outputConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(outputConsole, &consoleInfo);
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