#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<malloc.h>
#include<unistd.h>
#include<stdlib.h>
struct node {

	int data;
	struct node *next;

};

struct node *start = NULL;

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

void *threadfun(void *a)
{
	insert_last(10);
	sleep(2);
	insert_last(20);
	sleep(2);
	pthread_exit(NULL);

}
void *threadfun1(void *a)
{
	sleep(1);
	print();
	sleep(1);
	print();
	pthread_exit(NULL);
	
}


int main()
{
	pthread_t t1,t2;
	
	int ret;

	ret = pthread_create(&t1,NULL,threadfun,NULL);
	ret = pthread_create(&t2,NULL,threadfun1,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_exit(NULL);
	

	/*insert_last(10);
	insert_last(10);
	insert_last(10);
	insert_last(10);
		
	print();*/
	return 0;
}
