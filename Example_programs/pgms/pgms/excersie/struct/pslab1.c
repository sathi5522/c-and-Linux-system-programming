#include<stdio.h>

int main()
{
	struct x {
		int a;
		int *p;
	};
	struct x y = {10};
	y.p = &y.a;
	//*y.p = 20;
	struct x *z = &y;
	z->a = 20;
	printf("%d %d \n",*y.p,*z);
	
	return 0;
  
}
