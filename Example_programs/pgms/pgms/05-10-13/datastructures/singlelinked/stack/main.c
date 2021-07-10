#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<unistd.h>

struct node {

	int data;
	struct node *next;
};

struct node *start;

int insert_first(int num)
{

	struct node *new, *tmp;

	new = malloc(sizeof(struct node));
	
	new->data = num;
	new->next = start;
	
	start = new;

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
int delete_first()
{
	struct node *p;
	p = start;
	int ret;

	ret = p->data;
	start = p-> next;
	free(p);
	return;
}


int main()
{
	int ret;

	ret = insert_first(10 );
	ret = insert_first(20);
	ret = insert_first(30);
	ret = insert_first(40);

	print();

	ret = delete_first();
	print();
	ret = delete_first();
	print();
	ret = delete_first();
	print();
	ret = delete_first();
	
	return 0;
}

	
