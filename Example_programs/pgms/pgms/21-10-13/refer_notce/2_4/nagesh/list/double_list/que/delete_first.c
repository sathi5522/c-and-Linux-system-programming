#include "header.h"
#include <stdlib.h>
#include "error.h"

int delete_first(que_t **q)
{

	que_t *tmp ;
	int ret;
	
	tmp = *q;
	
	if(!tmp)
	{
		error_no = LISTEMPTY;
		return error_no;
	}
	

	if(!tmp->next)
	{
		ret = tmp->val;
				
		free(tmp);
		*q = NULL;
		return ret;
	}


	tmp->next->prev = NULL;

	ret = tmp->val;
	
	*q = tmp->next;

	free(tmp);
	
	return ret;


}
