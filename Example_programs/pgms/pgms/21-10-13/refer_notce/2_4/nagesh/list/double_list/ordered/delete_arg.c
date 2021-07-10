#include "header.h"
#include <stdlib.h>
#include "error.h"
int delete_arg(dlist_t **st,int num)
{

	dlist_t *tmp = *st;
	int ret;


	if(!tmp){         //if list is empty
		error_no = LIST_EMPTY;
		return error_no;
	}

	if(!tmp->next){
		ret = tmp->val;	
		*st = NULL;
		free(tmp);
		return ret;
		
	}
	
	




	while(tmp&&(num != tmp->val)){

		tmp = tmp->next;
	}

	
	if(!tmp){

		error_no = NOTFOUND;
		return error_no; //not found
	}

	
	if(*st == tmp){                            //if found at first;
		tmp->next->prev = NULL;	
		ret = tmp->val;
		*st = tmp->next;
		free(tmp);
		return ret;		
	}

	ret = tmp->val;
	tmp->prev->next = tmp->next;
	if(tmp->next) //if last
	tmp->next->prev = tmp->prev;
	free(tmp);
	
	return ret;


}

