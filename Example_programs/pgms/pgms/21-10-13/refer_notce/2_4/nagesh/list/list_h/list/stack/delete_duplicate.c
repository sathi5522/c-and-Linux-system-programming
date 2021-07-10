#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "error.h"

void delete_duplicate(stack_t **st)
{

	int num;
	stack_t *tmp, *del,*ref;
	ref = tmp = *st;

	if((!tmp) ||(!tmp -> next)){
	
		return ;
	}
	
	
	while(tmp)
	{
		num = tmp->val;
		tmp = tmp->next;
		while(tmp)
		{
			if(num == tmp->val)
			{
				del = tmp;
				del->prev->next = del->next;
				if(del->next)
				del->next->prev = del->prev;	
				free(del);
				
			}
			tmp = tmp->next;
		}
	
		
		tmp = ref->next;
		ref = ref->next;

	}



}
