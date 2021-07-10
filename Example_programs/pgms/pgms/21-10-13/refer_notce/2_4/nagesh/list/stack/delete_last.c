#include <stdlib.h>
#include "header.h"

int delete_last(stack_t **q)
{

	stack_t *tmp,*prev;
	tmp = *q;

	if(!tmp)	
	{
		return 0;
	}

	if(!tmp -> next){
		free(*q);
		return 0;	

	}


	while(tmp->next){
		prev = tmp;
		tmp = tmp->next;
	}

	prev->next = NULL;
	free(tmp);


	return 0;

}
