#include "Grid.h"

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