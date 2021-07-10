#include <stdio.h>

#define ISEVEN(data)   (data % 2)

int main()
{


	int data = 11, ret;

	ret = ISEVEN(data);
	if(ret > 0)
		printf("ODD");
	else
		printf("EVEN");
	
	return 0;
	
}
