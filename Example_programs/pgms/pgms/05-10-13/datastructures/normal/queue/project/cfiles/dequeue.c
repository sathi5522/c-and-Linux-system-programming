#include "header.h"

int dequeue(queue_t *que)
{
	int ret,i;

	ret = que->data[0];
	
	for (i = 0; i< que->cur; i++){
		que->data[i] = que->data[i+1];
	}
		que->cur --;
	return ret;
}

