#include<stdio.h>
#include"stack.h"

int pop(queue_t *p)

{
	int i,temp;
	if(p->curr_ele == 0)
		printf("queue is empty \n");
	temp  = p->data[0];
	for(i = 0 ; i < p->curr_ele;i++) {
		p->data[i] = p->data[i + 1];

	}
		p->curr_ele--;
	return temp;
}
