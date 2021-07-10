#include <stdio.h>
#include <stdlib.h>

int main()
{

	int *p,*q;
	int i;
	q = calloc(5,sizeof(int));
	if(q == NULL)
	{	
		perror("calloc:");
		exit(1);
	}
	p = q;
	*p = 10;
	printf("%d",*p);
	p++ ;
	*p= 20;
	printf("%d",*p);	


	
	
	free(q);
	return 0;

}
