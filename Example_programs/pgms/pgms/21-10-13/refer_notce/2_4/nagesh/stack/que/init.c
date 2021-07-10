#include "header.h"
//#include <stdio.h>
#include <string.h>
void queue_init(struct msg *q,int new)
{

	if(new > 0)
	{
		memset(q,new,sizeof(q));
	}
		memset(q,new,sizeof(q));


}
