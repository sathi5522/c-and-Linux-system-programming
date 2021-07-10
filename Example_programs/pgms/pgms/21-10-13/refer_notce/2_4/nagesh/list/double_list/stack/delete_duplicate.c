#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "error.h"

void delete_duplicate(stack_t **st)
{

	int num;
	stack_t *tmp, *del;
	tmp = *st;

	if((!tmp) ||(!tmp -> next)){
	
		return ;
	}
		

	while(tmp){
	
		num = tmp->val;
		tmp = tmp ->next;
		while(tmp->val != num)
		{
			tmp = tmp->next;
		}
		
		del = tmp;
		del->prev->next = del->next;

		tmp = tmp->next;	
		free(del);

	
	}



}
