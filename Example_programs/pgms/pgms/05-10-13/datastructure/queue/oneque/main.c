#include<stdio.h>
#include"queue.h"

int main()
{
	int ret;
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	print();
	ret = dequeue();
	printf("the delete value is %d\n",ret);
	print();
	return 0;
}
