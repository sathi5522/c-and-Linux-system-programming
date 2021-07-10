#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include "error.h"
int enque_last(que_t **q, int num)
{

	que_t *tmp,*new;
	tmp = *q;

	new = malloc(sizeof(que_t));
	if(!new)
	{
		printf("malloc:");
		error_no = MALLOC_FAILED;
		return error_no;
	}


	new->val = num;
	new->next = NULL;
	
	if(!tmp){                                    // list is empty
			
		new->prev = NULL;
		*q = new;
		error_no = FIRST_ELEMENT;
		return error_no;
	
	}

	while(tmp->next)
	{
		tmp = tmp->next;

	}	
	
	
		tmp -> next = new;
		new ->prev = tmp;
		
		error_no = SUCCESS;
		return error_no;
		

}
