#include "header.h"
#include <stdlib.h>

int delete_first(stack_t **q)
{
	stack_t *tmp;
	
	tmp = *q;

	if(!tmp)
	{
		return 0;
	}
	
	*q = tmp->next;

	free(tmp);

}

