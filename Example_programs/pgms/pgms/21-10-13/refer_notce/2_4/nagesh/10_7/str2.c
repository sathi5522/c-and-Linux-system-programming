
#include <stdio.h>
int main()
{


	struct a{
		
		int x;
		int y;
		int *z;
		int *l;
	}n = {10,20,&(n.x),&(n.y)};

	printf("%d\n",n.x);

	printf("%d\n",n.y);

	printf("%p\n",n.z);
}
