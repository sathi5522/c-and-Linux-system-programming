#include <stdio.h>

int sub(int x, int y)
{

	return x - y;
}

int _init()
{

	printf("sub loaded\n");
	
	return 0;
}

int _fini()
{


	printf("sub unloaded\n");
	return 0;
}
