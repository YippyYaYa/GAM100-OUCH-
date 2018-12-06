/******************************************************************************/
/*!
\file   Ascii.c
\author Ho Jun Hao
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This file contains the function for printing some extended ascii characters
*/
/******************************************************************************/
#include "Grid.h"
/*Takes in text file and promotes it to extended ascii characters*/
unsigned char Ascii(unsigned char i)
{
	switch (i) {
		unsigned char c;
	case '0':
		c = ' ';
		return  c;
		break;
	case '1':
		c = 176;
		return c;
		break;
	case '2':
		c = 177;
		return c;
		break;

	case '3':
		c = 178;
		return c;
		break;

	case '4':
		c = 219;
		return c;
		break;
	case '5':
		c = 220;
		return c;
		break;

	case '6':
		c = 223;
		return c;
		break;
	}
	return 0;
}	