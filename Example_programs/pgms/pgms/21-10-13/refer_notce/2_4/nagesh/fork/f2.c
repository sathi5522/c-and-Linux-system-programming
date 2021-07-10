#include <stdio.h>
#include <unistd.h>

int glob = 100;
int main()
{

	printf("parent message %d\n",glob);
	fork();

	printf("child message%d\n",glob);

	return 0;

}
