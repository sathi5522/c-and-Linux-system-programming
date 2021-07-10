#include "header.h"
#include <stdlib.h>
int delete_first(que_t **q)
{

	que_t *tmp;
	tmp = *q;

	if(!tmp)
	{
		return 0;
	}

	*q = tmp->next;
	
	free(tmp);
	return 0;

}
