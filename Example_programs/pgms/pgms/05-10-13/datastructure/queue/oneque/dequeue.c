#include<stdio.h>
#include"queue.h"

int dequeue(void)
{
	int i,temp;
	if(obj.curr_ele == 0)
		printf("queue is empty \n");
	temp  = obj.data[0];
	for(i = 0 ; i < obj.curr_ele;i++) {
		obj.data[i] = obj.data[i + 1];

	}
		obj.curr_ele--;
	return temp;
}
