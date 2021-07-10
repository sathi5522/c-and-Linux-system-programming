#include<stdio.h>
#include"queue.h"

void print()
{
	int i;
	for(i = 0; i<obj.curr_ele;i++) {
		printf("the value in queue is %d\n",obj.data[i]);
	}
}
