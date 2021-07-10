#include<stdio.h>

int div(int x,int y)
{
	int c;
	c = x / y;
	printf("%d\n",c);
}

int _init() {
	print("div nit function");
	return 0;
}
int _fini() {
	printf("div uninit function");
	return 0;
}
