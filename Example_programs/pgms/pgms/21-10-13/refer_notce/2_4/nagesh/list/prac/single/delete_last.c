#include "header.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
int delete_last(q_list **st)
{

	q_list *tmp,*prev;
	tmp = *st;
	int ret;
	if(!tmp){

		error_no = EMPTYLIST;
		return error_no;
	}


	if(! tmp->next){
	
//		ret = tmp->data->num;	
		*st = NULL;
		free(tmp->data);
		free(tmp);
		return 0;
	}

	while(tmp->next){

		prev = tmp;

		tmp = tmp->next;
	}


//		ret = tmp->data->num;
		prev->next = NULL;
		free(tmp->data);
		free(tmp);

		return 0;






}
