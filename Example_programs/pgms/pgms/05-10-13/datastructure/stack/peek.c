#include<stdio.h>
#include"stack.h"

int peek(queue_t *p)
{
	int temp;
	temp  = p->data[0];
	return temp;
}
