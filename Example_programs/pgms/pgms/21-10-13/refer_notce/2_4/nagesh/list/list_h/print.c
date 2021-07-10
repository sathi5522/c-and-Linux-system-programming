#include "header.h"
#include <stdio.h>

void print( que_t *q)
{

	while(q){

	printf("%d ", q->val);

	q = q->next;

	}

	printf("\n");


}
