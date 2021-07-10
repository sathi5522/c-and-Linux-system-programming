#include <stdio.h>
#include "header.h"

void print(que_t *q)
{

	while(q)
	{
		printf("%d ",q->val);
		q = q->next;

	}

	printf("\n");
	printf("**no more element**");
	printf("\n");
}
