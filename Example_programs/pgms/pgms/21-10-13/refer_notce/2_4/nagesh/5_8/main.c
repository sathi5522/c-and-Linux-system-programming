#include <stdio.h>
int div(int,int);
int mul(int,int);
int sub(int,int);
int add(int,int);

int main()
{

	int ret;
	ret = add(20,20);
	printf("sum : %d\n",ret);
	ret = sub(20,20);
	printf("diff : %d\n",ret);
	ret = mul(20,20);
	printf("mul : %d\n",ret);
	ret = div(20,20);
	printf("div : %d\n",ret);

	return 0;
}
