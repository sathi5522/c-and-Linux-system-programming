#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("before fork\n");

	fork();

	printf("after fork\n");

	return 0;
}

