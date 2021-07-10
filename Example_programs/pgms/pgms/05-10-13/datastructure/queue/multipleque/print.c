#include<stdio.h>
#include"queue.h"

void print(queue_t *p)
{
	int i;
	for(i = 0; i<p->curr_ele;i++) {
		printf("the value in queue is %d\n",p->data[i]);
	}
}
