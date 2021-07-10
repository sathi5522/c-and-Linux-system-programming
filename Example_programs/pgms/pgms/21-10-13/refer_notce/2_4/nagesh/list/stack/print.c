#include "header.h"
#include <stdio.h>

void print(stack_t *q)
{


	while(q)
	{
		printf("%d  ",q->val);
		q = q->next;
	}

	printf("\n");
}
