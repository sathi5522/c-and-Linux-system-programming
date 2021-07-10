#include <stdio.h>
#include "header.h"
int main()
{

	list_t *start = NULL;

	insert(&start,20);
/*      insert(&start,30);	

	insert(&start,50);
	insert(&start,50);
	insert(&start,35);
	insert(&start,45);
	
	insert(&start,10);

	insert(&start,60);*/
	


	print(start);


	delete_arg(&start,20);


	print(start);

}
