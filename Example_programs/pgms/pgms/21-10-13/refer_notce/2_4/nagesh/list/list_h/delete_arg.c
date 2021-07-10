#include <stdlib.h>
#include "header.h"
#include <stdio.h>

int delete_arg(que_t **q, int num)
{

	que_t *tmp,*prev;
	tmp = *q;

	if(!tmp){                    // list is empty
	
		return 0;
	}



	
/*	if(!tmp->next)  // list havin only one element
	{
		
		printf("%d\n",tmp ->val);
		free(*q);
		return 0;
	}*/

	while(tmp && (num != tmp->val)) //list having more no of elements
	{
		prev = tmp;
		tmp = tmp->next;
	}	
	
	if ( (!tmp) && (num != prev->val) ) // element not found
	{
		printf("element not found");
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
