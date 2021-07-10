#include <stdio.h>

void bin(unsigned long int a, short int b)
{
	 short int i = (b*8)-1;
	
	for(;i >= 0; i--)
		printf("%d ",(a >> i)&1);


}
