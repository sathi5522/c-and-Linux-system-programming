#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include "error.h"
int delete_first(stack_t **st)
{
	int ret;
	stack_t *tmp;
		
	tmp = *st;

	if(!tmp){
		error_no = LISTEMPTY;
		return error_no;
	}

	if(!tmp->next){
		ret = tmp->val;
		*st = NULL;
		free(tmp);
		return ret;
	}	

	ret = tmp->val;
	tmp->next->prev = NULL;
	*st = tmp->next;
	free(tmp);
	return ret;

}
