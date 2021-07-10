#include<stdio.h>
#include<malloc.h>
#include<unistd.h>
#include<stdlib.h>

struct node {

	int data;
	struct node *next;

};

struct node *start;

int insert_last(int num)
{

	struct node *new;
	struct node *tmp;

	new = malloc(sizeof(struct node));

	new->data = num;
	new->next = NULL;

	if(!start){
		start = new;
		return 0;
	}
	tmp = start;

	while(tmp->next){
		tmp = tmp->next;
	}
	tmp->next = new;


	return 0;
}

void print(void)
{
	struct node *p;
	p = start;

	while(p){
	printf("%d ", p->data);
	p = p->next;
	}
	printf("\n");
	return;
}

int delete_first(void)
{
	int ret;
	struct node *p;
	p = start;

	ret =  p->data;

	start = p -> next;
	free(p);

	return ret;
}

int delete_ele(int arg)
{
	struct node *tmp, *prev;
	tmp = start, prev;

	if(tmp->data == arg){
		start = tmp->next;
		free(tmp);
		return 0;
	}


	while(tmp && tmp->data != arg){
		prev = tmp;
		tmp = tmp->next;
	}
	if(tmp){
	prev->next = tmp->next;
	free(tmp);
	}
	else
		return -1;
	
}


int main()
{

	int i;
	i = insert_last(10);
	i = insert_last(20);
	i = insert_last(30);
	i = insert_last(40);
	i = insert_last(50);

	print();
	
	i = delete_ele(60);
	if(i<0)
		printf("element not found\n");

	print();
	i = delete_first();
	print();
	i = delete_first();
	print();
	i = delete_first();
	print();

	return 0;
}
		
		

	

	

	
