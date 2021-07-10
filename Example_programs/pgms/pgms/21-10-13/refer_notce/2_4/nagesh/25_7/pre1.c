#include <stdio.h>

#define ISSET(data,pos)   ((data)>>(pos-1))&1

int main()
{


	int data = 10, pos = 4, ret;

	ret = ISSET(data,pos);
	if(ret > 0)
		printf("set");
	else
		printf("not set");
	
	return 0;
	
}
