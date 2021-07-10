#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include "error.h"	
int main()
{
	
	int ret;	
	queue_t q1,q2;

	queue_init(&q1,0);
	queue_init(&q2,0);

	ret = enqueue(&q1,4);
	if(ret < 0)
	{
	 error_msg("enqueue:");
	 exit(1);
	}

		
        ret = enqueue(&q1,5);
        if(ret < 0)
        {
         error_msg("enqueue:");
	exit(2);
        }
	
	
  

        ret = enqueue(&q1,6);
        if(ret < 0)
        {
         error_msg("enqueue:");
        exit(2);
        }

	print(&q1);








	ret = dequeue(&q1);
	if(ret < 0)
	{
	 error_msg("dequeue:");
	exit(3);
	}
	printf("data is deleted %d\n",ret);

	print(&q1);


        ret = dequeue(&q1);
        if(ret < 0)
        {
        error_msg("dequeue:");
        exit(4);
        }



	return 0;

}
