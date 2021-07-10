#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *start;

int insert_first(int arg)
{
	struct node *new,*tmp;
	new = malloc(sizeof(struct node));
	if(!new)
		return -1;

	new->data = arg;
	new->next = NULL;
	if(!start) {
		start  = new;
		return 0;
	}

	tmp = start;

	new->next = tmp;
	start = new;
}
int insert_last(int arg)
{
	struct node *new,*tmp;
	new = malloc(sizeof(struct node));
	if(!new)
		return -2;
	new->data = arg;
	new->next = NULL;

	if(!start)
		start = new;
	tmp = start;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return 0;
}

int delete_first()
{
	struct node *tmp;
	tmp = start;
	start = start->next;
	free(tmp);
}

int delete_last()
{
	struct node *tmp,*pre;
	tmp = start;
	while(tmp->next) {
		pre = tmp;
		tmp = tmp->next;
	}
	pre->next = NULL;
	free(tmp);
}

int print()
{
	struct node *tmp;
	tmp = start;
	while(tmp) {
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
}


int main()
{
	printf("insert the elements\n");
	insert_first(10);
	insert_first(20);
	insert_first(30);
	insert_first(40);

	print();

/*	printf("delete the elements\n");

	insert_last(100);
	insert_last(200);
	insert_last(300);
	insert_last(400);

	print();
*/
	delete_first();
	print();

/*	delete_last();
	print();
*/	return 0;
}
