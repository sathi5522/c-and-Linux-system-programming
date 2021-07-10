#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
int main()
{
	int *p;
	p = malloc(sizeof(int));
	printf("%d\n",malloc_usable_size(p));
	*p = 10;
	printf("%d\n",*p);
	free(p);

	return 0;
}

