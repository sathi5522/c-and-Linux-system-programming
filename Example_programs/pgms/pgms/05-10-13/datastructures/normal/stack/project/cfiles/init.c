#include"header.h"
#include<string.h>
int stack_init(stack_t *stack)
{

	memset(stack->data, 0, sizeof(stack->data));
	stack->curr = 0;
	return 0;
}

