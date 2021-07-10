#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct s{
	int i;
	int *ptr;
	char a;
};

int main()
{
	struct s *obj[5];
	int x = 100;	
	*obj = calloc(5,5*sizeof(struct s));
	printf("%d\n",malloc_usable_size(obj[0]));
	obj[0]->i = 10;
	obj[0]->ptr = &x;
	printf("%d\n", obj[0]->i);
	printf("%d\n", *(obj[0]->ptr));

	return 0;
}
	
	
