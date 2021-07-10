#include<stdio.h>
#include"stack.h"

int main()
{
	queue_t q1;
	int ret;

	push(&q1,10);
	push(&q1,20);
	push(&q1,30);
	push(&q1,40);
	push(&q1,50);
	print(&q1);


	ret = pop(&q1);
	printf("the delete value is q1 %d\n",ret);

	print(&q1);
	ret= peek(&q1);
	printf("the peek value is %d\n",ret);
	
	return 0;
}
