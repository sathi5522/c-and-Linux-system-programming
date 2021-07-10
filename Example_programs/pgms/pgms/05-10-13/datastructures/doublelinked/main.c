#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct node {

	int data;
	struct node *next;
	struct node *previous;
} dlist_t ;


int insert_last(dlist_t **start,int arg)
{
	dlist_t *new, *tmp;
	new = malloc(sizeof(dlist_t));
	if(!new){
		perror("malloc");
		exit(1);
	}

	new->data = arg;
	new->next = NULL;

	if(!(*start)){
		new->previous = NULL;
		(*start) = new;
		return 0;
	}

	tmp = (*start);
	while(tmp->next)
		tmp = tmp->next;
	
	tmp->next = new;
	new->previous = tmp;

	return 0;
}
int insert_first(dlist_t **start, int arg)
{
	dlist_t *new, *tmp;
	new = malloc(sizeof(dlist_t));
	if(!new){
		perror("malloc");
		exit(2);
	}

	new->data = arg;
	new->previous = NULL;

	if(!(*start)){
			new->next = NULL;
			(*start) = new;
			return 0;
	}

	tmp = (*start);
	tmp->previous = new;
	new->next = tmp;

	(*start) = new;

	return 0;
}
		
int print_first(dlist_t *start)
{
	dlist_t *tmp;
	tmp = start;

	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return 0;
}

int print_last(dlist_t *start)
{
	dlist_t *tmp;
	tmp = start;

	while(tmp->next){
		tmp = tmp->next;
	}
	
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->previous;
	}
	printf("\n");
	return 0;
}

	
int delete_ele(dlist_t **start, int arg)
{
	dlist_t *tmp;

	tmp = (*start);
	while(tmp){
		if(tmp->data == arg){
			printf("Element %d found, we delete it now\n", arg);
			break;
		}
	tmp = tmp->next;
	}
	if(!tmp){
		printf("Element %d is not in list\n", arg);
		return -1;
	}

	if(tmp->data == (*start)->data){
		(*start) = tmp->next;
		free(tmp);
		return 0;
	}

	if(!tmp->next){
		tmp->previous->next = NULL;
		free(tmp);
		return 0;
	}

	tmp->next->previous = tmp->previous;
	tmp->previous->next = tmp->next;
	free(tmp);
	return 0;

}
	
int main()
{

	int ret;
	dlist_t *start = NULL;

	ret = insert_last(&start,10);
	ret = insert_last(&start,20);
	ret = insert_last(&start,30);
	ret = insert_last(&start,40);
	ret = insert_first(&start, 5);


	print_first(start);

	print_last(start);
	return 0;

}

