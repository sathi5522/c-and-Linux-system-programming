#include <stdio.h>

int main()
{

	struct a{

		int a1;
		int a2;
		}n[2];

		n[0].a1 = 10;
		n[0].a2 = 20;

		n[1].a1 = n[0].a1;
 
		n[1].a2 = n[0].a2;

		printf("%d\n",n[1].a1);

		printf("%d\n",n[1].a2);

}
