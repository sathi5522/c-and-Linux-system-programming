#include<stdio.h>
#include"list.h"
int print(struct node **start)
{
        struct node *tmp;
        tmp = *start;
        while(tmp) {
                printf("%d\n",tmp->data);
                tmp = tmp->next;
        }
}

