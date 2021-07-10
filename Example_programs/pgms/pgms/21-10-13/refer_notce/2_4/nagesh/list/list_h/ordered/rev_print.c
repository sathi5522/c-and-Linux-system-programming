#include "header.h"
#include <stdio.h>

void rev_print(list_t *q)
{
	
	//tmp = q->next;
	if(q)		
	{
	rev_print(q->next );
	
	printf("%d\n",q->val);}




}
