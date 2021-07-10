#include<stdio.h>
int main()
{
	struct h {
		int a;
		int b;
	};
	struct h obj = {10, 20};
//	struct h *p;

//	p = &obj;
//	printf("%d %d", sizeof(p), sizeof(*p));
	
	(&obj) -> a = 100;
	(&obj) -> b = 200;
	
	printf("%d%d", obj.a, obj.b);
	
}
