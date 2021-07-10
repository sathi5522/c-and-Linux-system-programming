#include<stdio.h>
#include"header.h"

int main()
{
	stack_t obj;

	stack_init(&obj);

	push(&obj, 10);
	push(&obj, 20);
	push(&obj, 30);
	push(&obj, 40);

	print(&obj);

	pop(&obj);
	print(&obj);
	pop(&obj);
	print(&obj);
	pop(&obj);
	print(&obj);
	return 0;
}
