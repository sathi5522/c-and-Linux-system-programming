#include <stdio.h>

int main()
{

	struct A{

		int a;
		int b;
		int c;
	}g;
	g.a = 10;
        g.b = 20;
	g.c =  g.a + g.b;
	printf("%d", g.c);
}
