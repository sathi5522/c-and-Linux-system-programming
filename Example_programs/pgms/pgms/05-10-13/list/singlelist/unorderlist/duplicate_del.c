#include<stdio.h>
#include<stdlib.h>

int dup_del(struct node **start)
{
	struct node *tmp,*prv;
	tmp = *start;
	if(tmp->data == tmp->next->data) {
		prv = tmp;
		tmp->next = prv->next;
		free(tmp);
	}
	else {
		tmp = tmp->next;
	}
	
}
