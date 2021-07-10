#include<stdio.h>
struct s {
	int a;
	int b;
};

void fun(struct s *x ,struct s  *y,struct s *sum)
{
	sum->a = x->a + y->a;
	sum->b = x->b + y->b;
}
int main()
{
	struct s obj1 ={10,20}, obj2 = {20, 30}, obj3;
	fun(&obj1, &obj2, &obj3);
	printf("%d %d\n", obj3.b,obj3.a);

	return 0;
}
	
