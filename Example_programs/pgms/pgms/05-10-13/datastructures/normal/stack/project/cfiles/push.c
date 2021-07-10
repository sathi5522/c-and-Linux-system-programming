#include"header.h"


int push(stack_t *stack, int arg)
{
	int i = stack->curr;
	if(stack->curr > MAX-1 )
		return -1;

	for(i; i > 0; i--)
		stack->data[i] = stack->data[i-1];
	stack->data[0]  = arg;

	stack->curr ++;
	return 0;
}


	
