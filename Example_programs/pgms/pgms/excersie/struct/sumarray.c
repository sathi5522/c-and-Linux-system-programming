#include<stdio.h>

int main()
{

	struct arraysum {
		int a[5];
		int b;
	};
	struct arraysum as;
	as.a[0] = 10;
	as.a[1] = 20;
	as.a[2] = 30;
	as.a[3] = 40;
	as.a[4] = 50;
	as.b = 0;
	int i = 0;
	for(;i < 5;i++) {
		as.b = as.b + as.a[i];
	}
	printf("%d\n",as.b);

	return 0;

}
