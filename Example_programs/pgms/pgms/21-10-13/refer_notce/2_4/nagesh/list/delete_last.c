#include <stdlib.h>
#include "header.h"

int delete_last(que_t **q)
{

	que_t *tmp;
	tmp = *q;
	
	while(tmp)
	{
		tmp = (*tmp)->next;
	}

	free(tmp);
	return 0;
}








