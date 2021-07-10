#include <stdio.h>

#define OFF(data,pos)   data & (~(1 << (pos - 1)))

int main()
{


	int data = 10, pos = 4, ret;

	 ret = OFF(10,4);
	
	printf("%d\n",ret);
	return 0;
	
}
