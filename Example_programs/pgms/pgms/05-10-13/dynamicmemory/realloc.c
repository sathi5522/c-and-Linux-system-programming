#include<stdio.h>
#include<malloc.h>

int main()
{
	int *p,*q;

	p = calloc(2,2*sizeof(int));

	*p = 10;
	*(p + 1) = 20;

	printf("%d\n%d\n",*p,*(p+1));

	q = realloc(p,2*sizeof(int));
	
	*q = 30;
	*(q+1) = 40; 
	printf("%d\n%d\n",*q,*(q+1));

	free(q);

	return 0;
}

	
