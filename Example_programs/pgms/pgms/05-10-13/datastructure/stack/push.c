#include<stdio.h>
#include"stack.h"

int push(queue_t *p,int new)
{
	int i;
	i =p->curr_ele;
	if(p->curr_ele > 99)
		printf("queue is full\n");
	for(;i>=0;i--) {
	p->data[i] = p->data[i-1];

	p->data[0] = new;
	}

}
