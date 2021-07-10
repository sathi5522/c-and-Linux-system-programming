#include <stdio.h>

#define ISSET(data,pos)  data = data | (1 << (pos - 1))

int main()
{


	int data = 10, pos = 3;

	ISSET(data,pos);
	
	printf("%d\n",data);
	return 0;
	
}
