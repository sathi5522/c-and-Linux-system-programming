#include <stdio.h>
#include "header.h"
#include "error.h"
#include <stdlib.h>
int main()
{
	int ret;
	
	que_t *start = NULL;
/*elments are enterint */
	ret = enque_last(&start,20);
	if(ret < 0){
		error_msg("enque_last:");
		exit(1);
	}


	
	ret = enque_last(&start,30);
	if(ret < 0){
		error_msg("enque_last:");
		exit(2);
	}


	ret = enque_last(&start,40);
	if(ret < 0){
		error_msg("enque_last:");
		exit(3);
	}


	ret = enque_last(&start,50);
	if(ret < 0){
		error_msg("enque_last:");
		exit(4);
	}

	print(start);
/*element removing*/
	ret = delete_first(&start);
	if(ret < 0){
		error_msg("delete_first:");
		exit(5);
	}

	printf("%d is deleted\n",ret);
	print(start);


	ret = delete_first(&start);
	if(ret < 0){
		error_msg("delete_first:");
		exit(6);
	}

	printf("%d is deleted\n",ret);
	print(start);

	ret = delete_first(&start);
	if(ret < 0){
		error_msg("delete_first:");
		exit(7);
	}

	printf("%d is deleted\n",ret);
	print(start);


	ret = delete_first(&start);
	if(ret < 0){
		error_msg("delete_first:");
		exit(8);
	}

	printf("%d is deleted\n",ret);
//	print(start);


	ret = delete_first(&start);
	if(ret < 0){
		error_msg("delete_first:");
		exit(9);
	}


	return 0;

}
