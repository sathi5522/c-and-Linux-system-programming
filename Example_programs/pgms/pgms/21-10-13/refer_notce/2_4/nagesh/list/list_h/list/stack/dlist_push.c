#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include "error.h"

int dlist_push(stack_t **st, int num)
{

	stack_t *tmp,*new;                           //st = start
	tmp = *st;
	
	new = malloc(sizeof(stack_t));
	if(!new)
	{
		error_no = MALLOC_FAILED;
		return error_no;		
	}

	new->val = num;
	new->prev = NULL;

	if(!tmp)
	{
		new->next = NULL;
		*st = new;
		return SUCCESS;                        //success
	}


	new->next = tmp;
	(*st)->prev = new;
	*st = new;	


	return SUCCESS;           //success



}
