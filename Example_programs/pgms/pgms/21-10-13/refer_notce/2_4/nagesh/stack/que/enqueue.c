#include "header.h"
#include "error.h"
int enqueue(struct msg *q,int num)
{
	int j;
	if((q -> curr_num) > 49)
	{
		error_no = FULL;
		return error_no;;
	}

//	int j = (q->curr_num);
	for(j = q->curr_num; j > 0;j--)
		q->number[j]=q->number[j-1];	

	q->number[0] = num;
	q->curr_num++;


//	q -> number[q->curr_num] = num;
//	q->curr_num++;
	
	return num;

}
