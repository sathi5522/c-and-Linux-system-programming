#include<stdio.h>
#include"header.h"
#include<malloc.h>
#include<stdlib.h>


int insert_first(queue_t **start, int arg)
{

	queue_t *new,*tmp;

	new = malloc(sizeof(queue_t));
	if(!new)
		return -1;

	new->data = arg;
	new->next = NULL;

	if(!(*start)){
		(*start) = new;
		return 0;
	}

	tmp= (*start);

	while(tmp->next){
		tmp = tmp->next;
	}

	tmp->next = new;
	return 0;
}

	

	
