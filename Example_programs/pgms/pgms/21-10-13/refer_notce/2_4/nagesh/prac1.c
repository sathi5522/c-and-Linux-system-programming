#include <stdio.h>

unsigned int sum(unsigned int *p, unsigned int c)
{

	unsigned int result = 0;
	while(c--){

		result = result + ( *(p+c));
		
		};

	return result;


}

int main()
{

	unsigned int x[5] ={20,10,10,10,10},z;
	unsigned int (*gn)(unsigned int * ,unsigned int ) = sum;
	
	z = (*gn)(x,5);
	printf("%u\n",z);
	
	return 0;

}
