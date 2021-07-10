#include "header.h"
#include <stdlib.h>
#include "error.h"
int insert(dlist_t **st, int num)
{

	dlist_t *tmp,*new,*last;
	tmp = *st;

	
	
	new = malloc(sizeof(dlist_t));
	if(!new){
		
		error_msg("malloc");
		error_no = MALLOC_FAILED;
		return error_no;
		}
	
	new->val = num;

	if(!tmp){                               //empty list

		new->prev = NULL;                
		new->next = NULL;
		*st = new;
		error_no = SUCCESS;
		return error_no;
	}

	
	while(tmp && (tmp->val < num)){ 
		
		last = tmp;
		tmp = tmp->next;
			
	}

	if(*st == tmp){                   //inserting first
		new->prev = NULL;
		new->next = tmp;
		tmp->prev = new;
		*st = new;
		error_no = SUCCESS;
		return error_no;
	}

	if(!tmp){                        //insering last

		new->next  = NULL;
		last->next = new;
		new->prev  = last;
		
		error_no = SUCCESS;
		return error_no;
		
	}


	new->prev = tmp->prev;          //inserting middle
	tmp->prev->next = new;
	new->next = tmp;
	tmp->prev = new;


	error_no = SUCCESS;
	return error_no;
	

}
