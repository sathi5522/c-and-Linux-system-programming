#include <stdlib.h>
#include "header.h"
#include <stdio.h>
#include "error.h"
int delete_first(q_list **st)
{


	q_list *tmp;
	tmp = *st;
	int ret;

	if(!tmp){
		error_no = EMPTYLIST;
		return error_no;
		}


	if(!tmp->next)
	{	ret = (tmp)->data->num;
		*st = NULL;
		free(tmp);
		return ret;
	}
	
	
	ret = tmp->data->num;
	*st = tmp->next;

	free(tmp);

	return ret;






}
