#include <stdio.h>
#include "header.h"

int main()
{
	stack_t *start = NULL;

	insert_first(&start,10);
	
	insert_first(&start,20);
	insert_first(&start,30);
	insert_first(&start,40);
	insert_first(&start,50);
	insert_first(&start,60);

	
	print(start);
	
	delete_last(&start);

	print(start);
}
