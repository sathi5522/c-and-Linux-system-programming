#include<stdio.h>
#include<stdlib.h>

int main()
{	
	int *p;
	p = calloc(5,5*sizeof(int));
	if(!p) {
		perror("error");
		exit(1);
	}
	*p = 10;
	*(p+1) = 20;
	*(p+2) = 30;
	*(p+3) = 40;
	*(p+4) = 50;

	printf("%d\n",*p);
	printf("%d\n",*(p+1));
	printf("%d\n",*(p+2));
	printf("%d\n",*(p+3));
	printf("%d\n",*(p+4));

	free(p);

	return 0;
}
