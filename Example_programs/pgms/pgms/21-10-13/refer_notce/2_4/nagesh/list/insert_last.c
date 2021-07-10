#include  "header.h"
#include   <stdlib.h>

int insert_last(que_t **q,int num)
{

	que_t *tmp,*new;

	tmp = *q;
	
	new = malloc(sizeof(que_t));
	new->val = num;
	new->next = NULL;
	if(!new){
		perror("malloc");
		exit(1);
	}
	
	if(!*q) {
		*q = new;
		return 0;
	}

	while(tmp->next){
	tmp = tmp->next;
	}
	tmp->next = new;	
		

	return 0;	


}
