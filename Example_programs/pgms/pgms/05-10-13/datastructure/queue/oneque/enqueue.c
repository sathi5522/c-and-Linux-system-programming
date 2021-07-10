#include<stdio.h>
#include"queue.h"
struct manager obj;
int enqueue(int new)
{
	if(obj.curr_ele > 99)
		printf("queue is full\n");
	obj.data[obj.curr_ele] = new;
	obj.curr_ele++;

}
