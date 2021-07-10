#include <stdio.h>

int div(int x, int y)
{

	return (x / y);
}


int _init()
{

	printf("loaded");
	return 0;
}

int _fini()
{

	printf("unloaded");
	return 0;
}
