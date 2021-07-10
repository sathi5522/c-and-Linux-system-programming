#include <stdio.h>
#include <unistd.h>


int main()
{
	int glob = 424;
	printf("parent message %d\n",glob);
	fork();

	printf("child message%d\n",glob);

	return 0;

}
