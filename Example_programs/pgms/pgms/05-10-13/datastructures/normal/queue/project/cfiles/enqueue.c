#include<stdio.h>
#include"header.h"


int enqueue(queue_t *que, int num)
{

	int i;

	if(que->cur > (MAX-1)){
		return QFULL;
	}

	que->data[que->cur] = num;
	que->cur ++;
	return SUCCESS;

}
	
