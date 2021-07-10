#include<stdio.h>
#include"list.h"
int main()
{
	struct node *start;
	insert_first(&start,10);
        insert_first(&start,20);
        insert_first(&start,30);
        insert_first(&start,40);

        print(&start);
	
	//delete_first(&start);
        
 	dup_del(&start);
	print(&start);	

	return 0;	
}
