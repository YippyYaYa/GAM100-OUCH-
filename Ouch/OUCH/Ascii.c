void Ascii(int i)
{
	switch (i) {
		char c;
	case 0:
		printf(" ");
		break;
	case 1:
		c = 176;
		printf("%c", c);
		break;
	case 2:
		c = 177;
		printf("%c", c);
		break;

	case 3:
		c = 178;
		printf("%c", c);
		break;

	case 4:
		c = 219;
		printf("%c", c);
		break;
	case 5:
		c = 220;
		printf("%c", c);
		break;

	case 6:
		c = 223;
		printf("%c", c);
		break;
	}
	return;
}	