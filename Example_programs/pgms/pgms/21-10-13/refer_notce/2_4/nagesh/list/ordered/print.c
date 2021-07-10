#include <stdio.h>
#include <stdlib.h>
#include "header.h"
void print(list_t *q)
{
	
	while(q)
	{
	printf("%d ",q->val);	
	q = q->next;
	

	};

	printf("\n");

	
}
