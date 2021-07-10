#include "header.h"
#include <stdlib.h>

int insert(dlist_t  **st, int num)
{

	dlist_t *tmp,*new,*ref;
	
	tmp = ref = *st;
	
	new = malloc(sizeof(dlist_t));
	if(!new){
		perror("malloc:");
		return 0;
		}
	new->val = num;
	
	if(!tmp){
		new->next = new;
		new->prev = new;
		*st = new;
		return 0;
	}
//	tmp = tmp->next;
	
	while( (tmp->next != (*st)) && (tmp->val < num) ){

		tmp = tmp->next;

	}

	if(tmp->next == (*st)){                             //only one lement

				
			new->prev = tmp;
			tmp->next = new;
			
			tmp->prev = new;
			new->next = ref;
			return 0;


	}	







			
	new->prev = tmp->prev;                                //inserting at middle
	tmp->prev->next = new;
	new->next = tmp;
	tmp->prev = new;
		










		return 0;

        } 

