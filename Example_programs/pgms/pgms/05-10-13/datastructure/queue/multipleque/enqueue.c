#include<stdio.h>
#include"queue.h"

int enqueue(queue_t *p,int new)
{
	if(p->curr_ele > 99)
		printf("queue is full\n");
	p->data[p->curr_ele] = new;
	p->curr_ele++;

}
