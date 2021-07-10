#include <stdio.h>

#define TWOBYFOUR(data1, data2, result)  result = data1;\
					 result = (result<<16)|data2

int main()
{

	unsigned short int a = 1, b = 1;
	
	unsigned int ret;

	TWOBYFOUR(a,b,ret); 
	
	printf("%u",ret);
	return 0;
	




}  
