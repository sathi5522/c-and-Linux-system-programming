#include <stdlib.h>
#include <stdio.h>

int main()
{

	int *p;
	
	p = malloc(sizeof(int));
	if(p == NULL)
	{
		perror("malloc");
		exit(1);
	}
	*p = 10;
	printf("%d",*p);
	free(p);


}
