#include <stdio.h>
#include "header.h"
int main()
{

	list_t *start = NULL,*ret;

	insert(&start,20);
        insert(&start,30);	

	insert(&start,50);
	insert(&start,50);
	insert(&start,35);
	insert(&start,45);
	
	insert(&start,10);

	insert(&start,60);
	ret = middle(&start);
	printf("%dis the middle value *****\n",ret->val);


//	print(start);
//	rev_print(start);

//	delete_arg(&start,20);
//	del_ref(start->next);
	print(start);
	delet(&start);
	print(start);

}
