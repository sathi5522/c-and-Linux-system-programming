#include <stdio.h>
#include <stdlib.h>

int main()
{

	int (*b)[4];


	b = calloc(3,sizeof(b[0]));
	if(!b)
	{
		perror("calloc::");
		exit(1);
	
	}
	b[0][0] = 23;
	b[0][1] = 22;
	b[0][2] = 32;
	printf("%d",b[0][2]);	
	

	free(b);

	return 0;



}
