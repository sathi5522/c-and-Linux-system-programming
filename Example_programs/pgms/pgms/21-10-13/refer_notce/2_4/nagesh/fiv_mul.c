#include <stdio.h>

int main()
{
	int no, rem;

	printf("enter any number\n");
	scanf("%d",&no);

	rem = no % 10;
	if(rem == 5 || rem == 0)

		printf("%d is multiple of 5 \n",no);
	
	else{
		printf("%d is not a multiple of 5\n",no);
	}

	return 0;
}

