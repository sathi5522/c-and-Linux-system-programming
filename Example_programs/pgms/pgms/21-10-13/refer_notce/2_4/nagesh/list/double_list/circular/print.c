#include "header.h"
#include <stdio.h>

void print(dlist_t *st)
{

	
	dlist_t *tmp;
	tmp = st;
	if(tmp){	
	printf("%d ",tmp->val);
	tmp = tmp->next;
	while(tmp != st){

		printf("%d ",tmp->val);	
	}
		
	printf("\n");
		
	}

}

