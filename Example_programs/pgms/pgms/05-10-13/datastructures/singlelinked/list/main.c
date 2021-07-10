#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<unistd.h>


struct node {

	int data;
	struct node *next;
};
typedef struct node list_t;

list_t *start = NULL;

int insert_first(int num)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if(!new){
		perror("malloc");
		exit(1);
	 }

	new->data = num;
	new->next = start;

	start = new;
	return 0;
}

int del_dup(void)
{
	list_t *tmp1,*tmp2,*prev;

	tmp1 = start;

	while(tmp1){
		prev = tmp1;
		tmp2 = tmp1->next;
		while(tmp2){
		if(tmp1->data == tmp2->data){
			prev->next = tmp2->next;
			free(tmp2);
			tmp2 = prev->next;
		}
		else{
			prev = tmp2;
			tmp2 = tmp2->next;
		}
		}
		tmp1 = tmp1->next;
	}		

	return 0;
}
int mid_ele(void)
{
	list_t *seq, *alt;

	seq = start;
	alt = start;
	while(alt && alt->next){
		seq = seq->next;
		alt = alt->next->next;
	}

	return seq->data;
}
int dele_ele(int num)
{

	list_t *tmp, *prev, *tmp1;
	
	tmp = start;

	while(tmp){
		if(num == tmp->data){
			printf("Element %d found\n", num);
			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}

	if(!tmp){
		printf("Element not found\n");
		return -1;
	}

	if(num == start->data){
		tmp1 = start;
		start = tmp1->next;
		free(tmp1);
		return 0;
	}

	if(!tmp->next){
		prev->next = NULL;
		free(tmp);

	}
	prev->next = tmp->next;
	free(tmp);
	return 0;
}			

int del_entire(void)
{
	list_t *tmp, *tmp1;
	tmp1 = start;	

	while(tmp1){
		tmp1 = start->next;
		free(start);
		start = tmp1;
	}
	return 0;
}	
		
int print(void)
{
	list_t *tmp;
	tmp = start;

	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	
	return 0;
}
int insert_last(int num)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if(!new){
		perror("malloc");
		exit(1);
	}
	new->data = num;
	new->next = NULL;

	if(!start)
	return 0;
}

		
int main()
{
	int ret;

	ret = insert_first(10);
	ret = insert_first(20);
	ret = insert_first(20);
	ret = insert_first(40);
	ret = insert_first(30);

	print();

	ret = del_dup();
	print();	
	ret = dele_ele(30);

	
	print();
//	ret = del_entire();
//	print();

	ret = mid_ele();
	printf("mid element is %d\n", ret);


	return 0;
}
	
