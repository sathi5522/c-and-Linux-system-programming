#include"header.h"

int pop(stack_t *stack)
{

	int i,ret;
	ret = stack->data[0];

	for(i=0; i<stack->curr; i++)
		stack->data[i] = stack->data[i+1];

	stack->curr --;

	return ret;
}
 
