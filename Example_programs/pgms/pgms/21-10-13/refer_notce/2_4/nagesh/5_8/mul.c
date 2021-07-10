#include <stdio.h>

int mul(int x, int y)
{

	return x * y;


}

int _init()
{

	printf("mul loaded\n");
	return 0;
}

int _fini()
{

	printf("mul unloaded\n");

	return 0;
}
