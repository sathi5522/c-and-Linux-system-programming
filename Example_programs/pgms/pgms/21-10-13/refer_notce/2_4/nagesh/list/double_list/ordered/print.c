#include "header.h"
#include <stdio.h>

void print(dlist_t *st)
{

	dlist_t *curr;
	if(st){
	while(st){
		curr = st;
		printf("%d ",st->val);
		st = st->next;

	}
	
	printf("\n");
	
	while(curr){

		printf("%d ",curr->val);
		curr = curr->prev;

	}

	printf("\n");


	}
}


