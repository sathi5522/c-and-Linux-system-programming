#include<stdio.h>
#include"dlist.h"

void print(dlist_t start)
{
	while(start){
		printf("%d\t",start->data);
		start = start->next;
	}
	printf("\n");
}
	
