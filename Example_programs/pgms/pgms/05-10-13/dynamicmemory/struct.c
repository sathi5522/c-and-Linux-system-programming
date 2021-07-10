#include<stdio.h>
//#include<malloc.h>
#include<stdlib.h>
struct s{
	int i;
	int *ptr;
	char a;
};

int main()
{
	struct s *obj;
	int x = 100;	
	obj = malloc(sizeof(struct s));

	obj->i = 10;
	obj->ptr = &x;
	printf("%d\n", obj->i);
	printf("%d\n", *(obj->ptr));

	return 0;
}
	
	
