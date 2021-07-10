#include<stdio.h>
void fun(int *s)
{
	printf("%d %d", *s, *(++s));
}
int main()
{
	int a[2] = {1, 2};
	fun(a);
	
	return 0;
}
