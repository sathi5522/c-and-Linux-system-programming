

#define DLIST_H

#include<stdlib.h>
#include<malloc.h>

struct node{

	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node *dlist_t;
int insert_first(dlist_t *,int);
int insert_last(dlist_t *,int);
int delete(dlist_t *,int);
void init_dlist(dlist_t *);
void print(dlist_t);
	
