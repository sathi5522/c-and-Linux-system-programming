#include "header.h"
#include <stdlib.h>

int insert_first(stack_t **q,int num)
{

	stack_t *tmp,*new;
	tmp = *q;
	new = malloc(sizeof(stack_t));
	if(!new){
			
		return 0;
	}
	new->val = num;
	
	if(!tmp){

	 new->next = NULL;
	 *q = new;			
	}

	new->next = tmp;
	*q = new;

	return 0;
}
