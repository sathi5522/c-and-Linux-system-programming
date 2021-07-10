#include <stdio.h>

int add(int x, int y)
{

	return x + y;
}

int _init()
{

	printf("add loaded\n");
	return 0;
}

int _fini()
{


	printf("add unloaded\n");
	return 0;
}
