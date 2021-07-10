#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "header.h"


int insert_first(q_list **st,void  *p)
{

	q_list *tmp,*alt= NULL;
	tmp  =  *st;

	alt = malloc(sizeof(q_list));
	if(alt < 0){
		error_no = MALLOC_FAILED;
		return error_no;

	}
	
	alt->data = p;
	if(!tmp){
	
		alt->next = NULL;
		*st = alt;
		error_no = SUCCESS;
		return error_no;

	}


	alt->next = tmp;
	*st = alt;
	
	error_no = SUCCESS;
	return error_no;

}
