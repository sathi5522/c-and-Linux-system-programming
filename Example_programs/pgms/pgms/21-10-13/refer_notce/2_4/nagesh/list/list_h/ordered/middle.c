#include "header.h"
#include <stdio.h>

list_t *  middle( list_t **q)
{
	list_t *seq =NULL,*alt = NULL;
	seq = alt =  *q;

	if(!seq)
	{
		return 0;
	}
	while(alt && alt->next){

		seq = seq->next;
		alt = alt->next->next;
		
	}

	return seq;	





}
