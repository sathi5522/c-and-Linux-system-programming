#include"dlist.h"

int main()
{
	dlist_t first;

	init_dlist(&first);

	insert_first(&first,10);
	insert_first(&first,20);
	insert_first(&first,30);
	insert_first(&first,40);
	insert_first(&first,50);
	insert_first(&first,60);
	insert_first(&first,70);

	insert_last(&first,70);
	insert_last(&first,60);
	insert_last(&first,50);
	insert_last(&first,40);
	insert_last(&first,30);
	insert_last(&first,20);
	insert_last(&first,10);

	print(first);

	delete(&first,10);
	print(first);
	/*delete(&first,60);
	print(first);
	delete(&first,40);
	print(first);
	delete(&first,20);
	print(first);
	delete(&first,100);
	print(first);*/

	return 0;
}


