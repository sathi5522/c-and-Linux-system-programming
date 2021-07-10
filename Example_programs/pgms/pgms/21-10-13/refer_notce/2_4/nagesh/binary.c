# include <stdio.h>

void bin(unsigned int a)
{
	 int i = 31;

	for(; i >= 0; i--)
		printf("%d",(a >> i)&1);
		printf("\n");
	
//	return 0;
}


