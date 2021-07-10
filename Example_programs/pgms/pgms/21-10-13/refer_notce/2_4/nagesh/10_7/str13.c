#include <stdio.h>

struct an{
	

	int a;
	int b;
	};




void sum(struct an *p, struct an *q, struct an  *r)
{

	r->a = p->a + q->a;

	r->b = p->b + q->b;
}


int main()
{


	struct an  a1, b1, ret;

	a1.a = 20;
	a1.b = 30;

	b1.a = 20;
	b1.b = 30;

	sum(&a1,&b1,&ret);

	printf("%d\n %d", ret.a,ret.b);

	return 0;
	
}
