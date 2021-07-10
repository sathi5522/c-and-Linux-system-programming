#include<stdio.h>
#include"dlist.h"

int insert_first(dlist_t *start,int arg)
{
	dlist_t new,tmp;

	new = malloc(sizeof(*new));

	if(!new)
		return -1;

	new->data = arg;
	new->prev = NULL;
	new->next = NULL;

	if(*start){
		new->next = *start;
		(*start)->prev = new;
	}
	*start = new;

	return 0;
}
