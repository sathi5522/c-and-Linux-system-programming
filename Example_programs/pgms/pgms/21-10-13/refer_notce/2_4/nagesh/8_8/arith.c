#include <stdio.h>
#include "header.h"
void arith()
{
	
	int ret;
	int (*fp)();
	fp = &add;
	ret = (fp)();
	printf(" sum : %d\n",ret);

/*	ret = sub(x,y);
	printf("sub : %d\n", ret);

	ret = mul(x,y);
	printf("mul = %d\n", ret);

	ret = div(x,y);
	printf("div = %d\n", ret);*/

	

}
