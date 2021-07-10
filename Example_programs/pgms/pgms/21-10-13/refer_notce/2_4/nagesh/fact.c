#include <stdio.h>

int fact(int a)
{
	int result=1, i;

	for(i = 1; i <= a; i++){
		
		result = result * i;

	}

	return result;
		
}

