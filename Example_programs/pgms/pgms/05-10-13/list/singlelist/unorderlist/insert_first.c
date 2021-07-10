#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int insert_first(struct node **start,int arg)
{
        struct node *new,*tmp;
        new = malloc(sizeof(struct node));
        if(!new)
                return -1;

        new->data = arg;
        new->next = NULL;
        if(!(*start)) {
                *start  = new;
                return 0;
        }

        tmp = *start;

        new->next = tmp;
        *start = new;
}

