#include"header.h"
#include<stdio.h>

int print(queue_t *que)
{

	int i;
	for(i=0; i < que->cur; i++)
	{
		printf("%d ", que->data[i]);
	}
	printf("\n");
	return SUCCESS;
	
}

