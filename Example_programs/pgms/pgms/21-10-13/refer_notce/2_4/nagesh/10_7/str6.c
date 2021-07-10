#include <stdio.h>

int main()
{
	

	struct a{
		
		int a1;
		int b1;

	}s = {1,2},*p = &s;

	printf("%d\n",p -> a1);
	printf("%d\n",p -> b1);




}
