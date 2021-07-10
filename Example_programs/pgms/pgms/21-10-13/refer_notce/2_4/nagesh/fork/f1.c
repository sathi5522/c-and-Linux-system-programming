#include <stdio.h>
#include <unistd.h>
int main()
{

	printf("parent message\n");
	fork();

	printf("child message\n");

	return 0;

}
