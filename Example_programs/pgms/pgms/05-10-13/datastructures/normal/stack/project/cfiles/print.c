#include"header.h"
#include<stdio.h>
int print(stack_t *stack)
{

	int i;
	for(i = 0; i < stack->curr; i++)
		printf("%d ", stack->data[i]);

	printf("\n");
	return 0;
}
