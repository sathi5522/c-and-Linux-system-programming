#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int del_ref(list_t *q)
{
	list_t *temp;
	temp = q->next;	
	q->val = (q->next)->val;
	q->next = (q->next)->next;
	
	free(temp);

	return 0;
}
