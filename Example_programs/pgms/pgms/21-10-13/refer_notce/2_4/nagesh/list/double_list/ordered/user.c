#include "header.h"
#include <stdio.h>
#include "error.h"
#include <stdlib.h>
int main()
{

	dlist_t *start = NULL;
	int ret;

	ret = insert(&start,10);
	if(ret < 0){
		error_msg("insert1:");
		exit(1);
	}
		

	ret = insert(&start,30);
	if(ret<0){
		error_msg("insert2:");
		exit(2);
	}


	ret = insert(&start,25);
	if(ret < 0){
		error_msg("insert3:");
		exit(3);
	}



	ret = insert(&start,60);
	if(ret< 0){
		error_msg("insert4:");
		exit(4);
	}


	ret = insert(&start,5);
	if(ret<0){
		error_msg("insert5:");
		exit(5);
	}

	print(start);
////////////////////////////////////////////////////////////
	ret = delete_arg(&start,10);
	if(ret < 0){
		error_msg("delete1:");
		exit(6);
	}

	print(start);
/////////////////////////////////////////////////////1	
	ret = delete_arg(&start,5);
	if(ret < 0){
		error_msg("delete2:");
		exit(7);
	}


	print(start);
/////////////////////////////////////////////////////2
	ret = delete_arg(&start,30);
	if(ret < 0){
		error_msg("delete3:");
		exit(8);
	}
	print(start);
///////////////////////////////////////////////////3
	ret = delete_arg(&start,25);
	if(ret < 0){
		error_msg("delete4:");
		exit(9);
	}
	print(start);
	
//////////////////////////////////////////////////4
	ret = delete_arg(&start,60);
	if(ret < 0){
		error_msg("delete5:");
		exit(10);
	}

	print(start);
//////////////////////////////////////////////////5
}
