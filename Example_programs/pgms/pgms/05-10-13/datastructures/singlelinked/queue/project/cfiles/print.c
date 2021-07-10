#include<stdio.h>
#include"header.h"

int print(queue_t *start)
{

	queue_t *tmp;

	tmp = start;

	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");

	return 0;
}

