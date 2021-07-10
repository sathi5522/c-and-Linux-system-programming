#include<stdio.h>

int main()
{

	struct sum {
		int a;
		int b;
		int c;
	};
	struct sum s1;
	s1.a = 10;
	s1.b = 20;
	s1.c = s1.a + s1.b;
	printf("the sum of:%d\n",s1.c);
	
	return 0;

}
