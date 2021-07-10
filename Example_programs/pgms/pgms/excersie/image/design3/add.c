#include<stdio.h>

int add(int x,int y)
{
	int c;
	c = x + y;
	printf("%d\n",c);
}

int _init() {
	printf("add init function");
	return 0;
}
int _fini() {
	printf("add uninit function");
	return 0;
}
