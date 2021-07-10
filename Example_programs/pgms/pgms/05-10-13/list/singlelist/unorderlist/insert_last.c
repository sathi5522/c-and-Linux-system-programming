#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int insert_last(struct node **start,int arg)
{
        struct node *new,*tmp;
        new = malloc(sizeof(struct node));
        if(!new)
                return -2;
        new->data = arg;
        new->next = NULL;

        if(!(*start))
                *start = new;
        tmp = *start;
        while(tmp->next)
                tmp = tmp->next;
        tmp->next = new;
        return 0;
}

