#include <stdio.h>

	struct msg{
		int a;
		int b;
		
		};


void sum(struct msg *p, struct msg *q, struct msg *r)
{
	r -> a = p -> a + q-> a;

	r -> b = p -> b + q-> b;


}


int main()
{
	struct msg obj1 = {20,30},obj2 = {10,20},obj3;
	sum(&obj1,&obj2,&obj3);
	printf("%d\n%d",obj3.a,obj3.b);
	return 0;
}
