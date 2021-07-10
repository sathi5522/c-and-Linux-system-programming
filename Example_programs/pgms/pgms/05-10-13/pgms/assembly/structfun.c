#include<stdio.h>

struct s {
	int a;
	int b;
};
void fun(struct s *p)
{
	p->b = p->a;
}

int main()
{
	struct s obj = {1, 2};
	fun(&obj);

	return 0;
}
