#include <stdio.h>

int eve(int a)
{
	return (a % 2 == 0) ? 1: 0;
			
}

int main()
{

	int x, ret;	

	x = 20;
	ret = eve(x);
	
	if(ret)
		printf("%d is even number \n ",x);
	else{

		printf("%d is odd number \n",x);
	}


	return 0;
}
