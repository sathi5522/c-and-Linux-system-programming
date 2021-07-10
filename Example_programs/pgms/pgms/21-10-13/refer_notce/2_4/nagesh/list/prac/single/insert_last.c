#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

int insert_last(q_list **st, struct msg *p)
{

	q_list *tmp,*alt;

	tmp = *st;

	alt = malloc(sizeof(q_list));
	if(alt < 0)
	{
		error_no = MALLOC_FAILED;		
		return 	error_no;;
	}

	alt->data = p;
	alt->next = NULL;
	
	if(!tmp)
	{
		*st = alt;
		error_no = SUCCESS;
		return error_no;
	}

	while(tmp->next){
		tmp = tmp->next;

	}	
	tmp->next = alt;

	error_no = SUCCESS;
	return error_no;
	
	
}
