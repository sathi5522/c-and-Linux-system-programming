#include"header.h"
#include<string.h>

void que_init(queue_t *que)
{
	memset(que->data, 0, sizeof(que->data));
	que->cur = 0;
	return;
}

