#include <stdio.h>
#include "header.h"

void print(queue_t *q)
{

	int i;
	for(i = 0; i < (q->curr_num); i++)
		printf("%d ",q->number[i]);
		printf("\n");

}
