#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int insert(list_t **q,int num)
{
	list_t *tmp,*new,*prev;


	tmp = *q;

	new = malloc(sizeof(list_t));
	if(!new)
	{
		perror("malloc:");
		exit(1);
	}


	new->val = num;
	
	if(!tmp)                      //if list is empty
	{
		new->next = NULL;
		*q = new;
		return 0;
	}

	while(tmp && (num > (tmp->val)) )
	{
		prev = tmp;
		tmp = tmp -> next;
	}

	if(tmp == NULL)
	{	
          prev->next = new;
	  new-> next = NULL;
		return 0;
	}

	if(tmp == *q)
	{
	new->next = tmp;
	*q = new;
	return 0;
	}



	new->next = tmp;
	prev->next = new;	

	return 0;


	

}
