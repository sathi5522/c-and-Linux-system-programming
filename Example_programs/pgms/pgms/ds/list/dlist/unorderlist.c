#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *next,*prev;
};

struct node *start;

/*insert first in double linked list*/
int insert_first(int num) {
	struct node *new,*tmp;
	new = malloc(sizeof(struct node));
	
	if(!new) 
		return -1;
	new->data = num;
	new->next = NULL;
	new->prev = NULL;
	if(!start) {
		
		start = new;
		return 0;
	}

	tmp =start;

	new->next = tmp;
	tmp->prev = new;
	start = new;
}

/*insert last in double linked list*/
int insert_last(int num) {
	struct node *tmp,*new;
	new = malloc(sizeof(struct node));
	
	if(!new) 
		return -1;
	new->data = num;
	new->next = NULL;
	new->prev = NULL;	
	if(!start) {
		start = new;
		return 0;
	}
	
	tmp = start;
	
	while(tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = new;
	new->prev = tmp;

	return 0;
}

/*delete first in double linked list*/
void delete_first() {
	struct node *tmp;
	tmp = start;
	start = start->next;
	start->prev = NULL;
	free(tmp);
}

/*delete last in double linked list*/
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

/*find middle element in double linked list*/
int mid_ele() {
	struct node *seq,*alt,*tmp;
	seq = start;
	alt = start;
	while(alt && alt->next) {
		seq = seq->next;
		alt = alt->next->next;
	}
	return seq->data;

}


void print() {
	struct node *tmp,*cur;
	tmp = start;
	while(tmp) {
		cur = tmp;
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	while(cur) {
		printf("%d ",cur->data);
		cur = cur->prev;
	}
	printf("\n");
}


int main() {
	int a;

	insert_last(10);
	insert_last(50);
	insert_last(60);
	insert_last(30);
	insert_last(20);

	print();
	delete_first();
	print();
	/*a = mid_ele();
	printf("mid ele: %d\n",a);
	*/
	return 0;
}
