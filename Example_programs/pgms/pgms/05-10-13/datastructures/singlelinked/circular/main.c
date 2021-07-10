#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node {

		int data;
		struct node *next;
} circ_t;

circ_t *start = NULL;

int insert_last(int num)
{

	circ_t *new,*tmp;
	new = malloc(sizeof(circ_t));
	if(!new){
		perror("malloc");
		exit(1);
	}

	new->data = num;
	if(!start){
		start = new;
		start->next = start;
		return 0;
	}

	tmp = start;

	while(tmp->next != start){
		tmp = tmp->next;
	}

	tmp->next = new;
	new->next = start;
	return 0;
}

int print(void)
{

	circ_t *tmp;

	tmp = start;

	while(tmp->next != start){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->data);

}
int insert_first(int arg)
{
	circ_t *new, *tmp;
	new = malloc(sizeof(circ_t));
	if(!new){
		perror("malloc");
		exit(2);
	}

	new->data = arg;
	
	if(!start){
		start = new;
		start->next = start;
		return 0;
	}
	tmp = start;
	while(tmp->next != start){
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = start;
	start = new;

	return 0;
}

int main()
{

	int ret;
	ret = insert_first(1);
	print();
	ret = insert_last(10);
	print();
	ret = insert_last(20);
	print();
	ret = insert_first(5);
	print();

	return 0;
}

