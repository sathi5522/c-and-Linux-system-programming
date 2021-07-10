#include <stdio.h>

int main()
{

	unsigned  short *a ;
	
	unsigned  short int b = 0xffff, c = 0xeeee;
	unsigned int d;

	a = (short *)&d;
	*a = b;
	*(a + 1) = c;
	
	printf("%x",d); 

	

	 
	
	
	return 0;



}
