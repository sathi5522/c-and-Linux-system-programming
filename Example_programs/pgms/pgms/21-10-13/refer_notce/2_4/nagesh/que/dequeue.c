#include "header.h"
#include "error.h"

int dequeue(struct msg *q)
{

	int i,tmp;
	if((q->curr_num) < 0)
	{
		error_no = EMPTY;
		return error_no;
	}

	tmp = q->number[0];
	for(i = 0;i < q->curr_num;i++)
		q->number[i] = q->number[i+1];

	q->curr_num--;

	return tmp;
}
