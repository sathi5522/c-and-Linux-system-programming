#include<stdio.h>
#include"header.h"

int main()
{
	queue_t obj,que;
	que_init(&obj);
	que_init(&que);
	int ret;
	ret = enqueue(&obj,10);
	ret = enqueue(&obj,20);
	ret = enqueue(&obj,30);
	ret = enqueue(&obj,40);
	ret = enqueue(&obj,50);

	print(&obj);

	dequeue(&obj);
	print(&obj);
	dequeue(&obj);
	print(&obj);
	dequeue(&obj);
	print(&obj);
	dequeue(&obj);

	return 0;
}
