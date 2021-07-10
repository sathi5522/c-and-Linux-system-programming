#include "header.h"
#include <stdio.h>
#include <stdlib.h>
void print(stack_t *st)
{
			
	stack_t *curr;


	if(!st){

	exit(1);

	}	
	while(st)
	{
		curr = st;
		printf(" %d ", st->val);
		st = st->next;
	} 

	printf("\n");

	while(curr)
	{
		printf("%d ",curr->val);
		curr = curr->prev;
	}

	printf("\n");


};
