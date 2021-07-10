#include<stdio.h>
#include"queue.h"

int main()
{
	queue_t q1,q2;
	int ret;

	enqueue(&q1,10);
	enqueue(&q1,20);
	enqueue(&q1,30);
	enqueue(&q1,40);
	enqueue(&q1,50);
	print(&q1);


	ret = dequeue(&q1);
	printf("the delete value is q1 %d\n",ret);

	print(&q1);
	
	enqueue(&q2,100);
	enqueue(&q2,200);
	enqueue(&q2,300);
	enqueue(&q2,400);
	enqueue(&q2,500);
	print(&q2);


	
	ret = dequeue(&q2);
	printf("the delete value is q2%d\n",ret);

	print(&q2);
	return 0;
}
