#include"dlist.h"

int delete(dlist_t *start,int arg)
{
	dlist_t tmp;

	tmp = *start;

	if((*start)->data == arg){
			(*start)->next->prev = NULL;
			*start = (*start)->next;

//	go to SUCESS

	}
	
	while(tmp && tmp->data != arg){
			tmp = tmp->next;
			
			if(!tmp)
				return -1;
			if(tmp->next){
				tmp->prev->next  = tmp->next;
				tmp->next->prev = tmp->prev;

//			go to SUCESS

			}
	}
//	SUCESS;

	free(tmp);

	return 0;

}

