#include <stdio.h>
#include "header.h"
#include <stdlib.h>

int delete_arg(list_t **q,int num)
{

	list_t *tmp,*prev;
	
	tmp = *q;

	if(!tmp)                       //list is empty
	{
		return 0;
	}	

	while(tmp && (num != tmp->val))
	{
		prev = tmp;
		tmp = tmp->next;
	}	
	if(tmp == *q)
	{
		*q = tmp->next;
		free(tmp);
		return 0;
	}

	prev->next = tmp->next;
	free(tmp);
	




	return 0;


}
