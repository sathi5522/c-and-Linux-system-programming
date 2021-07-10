#include "header.h"

void display(q_list *p,  void (*fp)(void *))
{
	while(p) {
		(*fp)(p);
		p = p->next;
		
	}
}
