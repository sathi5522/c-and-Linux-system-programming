#include <stdlib.h>
#include "header.h"


int delete_arg(que_t **q, int num)
{

	que_t *tmp,*prev;
	tmp = *q;

	if(!tmp){                    // list is empty
	
		return 0;
	}

	
	if((num == tmp->val )&&(tmp->next = NULL))  // list havin only one element
	{
		free(*q);
		return 0;
	}

	while(tmp && (num != tmp->val)) //list having more no of elements
	{
		prev = tmp;
		tmp = tmp->next;
	}	
	
	if ( (tmp = NULL) && (num != prev->val) ) // element not found
	{

		return 0;            
	}

	if(tmp == *q)             //if value found at first node
	{
		*q = tmp->next;
		free(tmp);
		return 0;
	}

	prev->next = tmp->next; // if value found any where except first node
	free(tmp);	
	

	return 0;


}
