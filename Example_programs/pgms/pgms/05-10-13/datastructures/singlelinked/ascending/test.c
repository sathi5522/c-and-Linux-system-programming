#include<stdio.h>
#include<malloc.h>
#include<unistd.h>
#include<stdlib.h>

struct node {

	int data;
	struct node *next;
};

struct node *start;

int insert(int arg)
{
	struct node *new,*tmp, *prev;

	new = malloc(sizeof(struct node));
	if(!new)
		return -1;
	new->data = arg;
	new->next = NULL;

	if(!start || start->data > new->data){
		new->next = start;
		start = new;
		return 0;
	}

	tmp = start;

	while(tmp && new->data > tmp->data){
		prev = tmp;
		tmp = tmp->next;
	}
	
	prev->next = new;
	new->next = tmp;


	return 0;
}

void print(void)
{

	struct node *tmp;
	tmp = start;
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	printf("\n");
	return;
}


int main()
{

	int ret;

	ret = insert(10);
	ret = insert(2);
	ret = insert(40);
	ret = insert(12);
	ret = insert(5);
	ret = insert(50);

	print();
	
	return 0;
}

	
