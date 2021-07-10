#include<stdio.h>

int main()
{
	int a[2][3] = {{10,20,30},{40,50,60}};
	int i = 0;
	for(;i < 5; i++) {
		printf("%d\n",a[i]);
	}

	return 0;
}
