#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int delete_last(struct node **start)
{
        struct node *tmp,*pre;
        tmp = *start;
        while(tmp->next) {
                pre = tmp;
                tmp = tmp->next;
        }
        pre->next = NULL;
        free(tmp);
}
