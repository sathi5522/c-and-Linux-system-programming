#include  "header.h"
#include <stdio.h>

void print(q_list *st)
{

	
        struct msg {

                int num;
                char name[10];
        };
	
	struct msg *q= NULL;
	
	
	while(st){
		q = st->data;
		printf("num = %d\n",q->num);
		printf("name = %s\n",q->name);
		
		st = st->next;		
		};










}
