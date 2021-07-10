#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{

	que_t *start = NULL;

	insert_last(&start, 10);
	insert_last(&start, 20);
//	insert_last(&start, 30);
	print(start);
	
//	delete_first(&start);
	
	delete_arg(&start,10);

	print(start);


	return 0;








}
