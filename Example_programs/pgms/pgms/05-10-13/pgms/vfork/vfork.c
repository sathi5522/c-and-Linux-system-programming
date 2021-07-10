#include<stdio.h>

int main()
{
	printf("before vfork\n");
	vfork();
	printf("after vfork\n");

	return 0;
}
