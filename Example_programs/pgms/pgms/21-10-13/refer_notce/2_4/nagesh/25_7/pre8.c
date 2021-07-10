#include <stdio.h>

#define TOGG(data,pos)   (data)^(1 << (pos - 1))

int main()
{


//	int data = 10, pos = 4, ret;
	int ret;
	ret = TOGG(2,4);
	printf("%d\n",ret);
	
	return 0;
	
}
