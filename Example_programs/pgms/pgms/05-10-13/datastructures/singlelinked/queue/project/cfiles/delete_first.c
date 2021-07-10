#include<stdio.h>
#include"header.h"
#include<malloc.h>
#include<stdlib.h>

int delete_first(queue_t **start)
{
		queue_t *tmp;
		int ret;
		tmp = (*start);
		ret = tmp->data;
	
		(*start) = tmp->next;

		free(tmp);

		return ret;

}
