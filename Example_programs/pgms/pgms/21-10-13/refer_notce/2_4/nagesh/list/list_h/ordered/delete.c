#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int delet(list_t **q)
{

	list_t *tmp= NULL,*del = NULL;
	tmp = *q;
	while(tmp){
		*q = tmp->next;;
		free(tmp);

		tmp = *q;
	}
	

	return 0;
}
