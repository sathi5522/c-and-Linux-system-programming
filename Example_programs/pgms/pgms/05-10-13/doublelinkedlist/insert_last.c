#include"dlist.h"
#include<stdio.h>

int insert_last(dlist_t *start,int arg)
{
	dlist_t new,tmp;

	new = malloc(sizeof(*new));

	if(!new)
		return -1;

	new->data = arg;
	new->next = NULL;
	
	if(!*start){
		insert_first(start,arg);
	}
	tmp = *start;
	
	while(tmp->next)
		tmp = tmp->next;
	
	tmp->next = new;
	new->prev = tmp;

}
	

