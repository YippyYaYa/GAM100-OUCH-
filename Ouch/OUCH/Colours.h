#pragma once
#include <windows.h>

/* All colour definitions goes here */
#define PLAYER_COLOUR 6  /* Brown */
#define ENEMY_COLOUR 12 /* LIGHT RED */
#define RED 4
#define PUSHABLE 3
#define DESTROYABLE 11
#define END 2

/* Other Colours here if needed, can be added on top under a suitable name */
/*

The numbers at the back of the colour named is the number to be used for that colour

#define <smth> 0 gives u black
 
 There are more colours that can be used but gotta search online, but quite limited types

#define BLACK 0
#define BLUE  1
#define GREEN 2
#define CYAN  3

#define MAGENTA 5
#define BROWWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

*/

void Colours_Init();
void Colours_SetColor(WORD newColor);
void Colours_ResetColor();