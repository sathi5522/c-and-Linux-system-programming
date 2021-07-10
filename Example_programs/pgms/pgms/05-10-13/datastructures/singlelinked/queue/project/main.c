#include<stdio.h>
#include"header.h"

int main()
{
	int ret;
	queue_t *start = NULL;
	queue_t obj;

	ret = insert_first(&start, 10);
	if(ret)
		printf("success");
	
	insert_first(&start, 20);
	if(ret)
		printf("success");
	insert_first(&start, 30);
	if(ret)
		printf("success");
	insert_first(&start, 40);
	if(ret)
		printf("success");

	print(start);
	ret = delete_first(&start);
	printf("deleted element : %d\n", ret);
	print(start);
	ret = delete_first(&start);
	printf("deleted element : %d\n", ret);
	print(start);
	
	return 0;
}

