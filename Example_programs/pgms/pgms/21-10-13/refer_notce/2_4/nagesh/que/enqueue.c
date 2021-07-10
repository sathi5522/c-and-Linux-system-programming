#include "header.h"
#include "error.h"
int enqueue(struct msg *q,int num)
{

	if((q -> curr_num) > 49)
	{
		error_no = FULL;
		return error_no;;
	}
	q -> number[q->curr_num] = num;
	q->curr_num++;
	
	return num;

}
