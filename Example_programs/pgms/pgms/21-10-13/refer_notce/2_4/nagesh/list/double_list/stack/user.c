#include <stdio.h>
#include "header.h"
#include "error.h"
#include <stdlib.h>
int main()
{
	stack_t *start = NULL;
	int ret;

	ret = dlist_push(&start,10);
	if(ret < 0)
	{
		error_msg("dlist_push1:");
		exit(1);
	}
	
//	print(start);	



	ret = dlist_push(&start,10);
	if(ret < 0)
	{
		error_msg("dlist_push1:");
		exit(2);
	}
	
//	print(start);	


	ret = dlist_push(&start,20);
	if(ret < 0)
	{
		error_msg("dlist_push1:");
		exit(3);
	}
	
//	print(start);	


	ret = dlist_push(&start,20);
	if(ret < 0)
	{
		error_msg("dlist_push1:");
		exit(4);
	}
	
//	print(start);	

	ret = dlist_push(&start,50);
	if(ret < 0)
	{
		error_msg("dlist_push1:");
		exit(5);
	}
	
	print(start);	


	delete_duplicate(&start);
	
//	print(start);
/*	ret =	delete_first(&start);
	if(ret < 0)
	{
		error_msg("delete_first");
		exit(6);
	}


//	print(start);
	

	ret =	delete_first(&start);
	if(ret < 0)
	{
		error_msg("delete_first");
		exit(7);
	}


//	print(start);
	
	ret =	delete_first(&start);
	if(ret < 0)
	{
		error_msg("delete_first");
		exit(8);
	}


//	print(start);
	
	ret =	delete_first(&start);
	if(ret < 0)
	{
		error_msg("delete_first");
		exit(9);
	}


//	print(start);
	
	ret =	delete_first(&start);
	if(ret < 0)
	{
		error_msg("delete_first");
		exit(10);
	}


//	print(start);
	
	ret =	delete_first(&start);
	if(ret < 0)
	{
		error_msg("delete_first");
		exit(11);
	}


//	print(start);*/
	
	return 0;

}
