#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int delete_first(struct node **start)
{
        struct node *tmp;
        tmp = (*start);
        (*start) = (*start)->next;
        free(tmp);
}

