#include <stdio.h>
#define  READBY(result,fb,sb)   fb = result & 0x0000ffff;\
				sb = (result >> 16) & 0x0000ffff


int main()
{

	unsigned short int a,b;
	int c = 0x0000000f;

	READBY(c,a,b);

	printf("%hu\n",a);
	printf("%hu",b);

	return 0;

}
