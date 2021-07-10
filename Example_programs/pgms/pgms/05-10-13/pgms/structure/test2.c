#include<stdio.h>
struct s{
	char c[10];
};
void fun(struct s *p)
{
	strcpy(p ->c,"jeet");
}
int main()
{
	struct s obj;
	fun(&obj);
	printf("%s",  obj.c);
}
