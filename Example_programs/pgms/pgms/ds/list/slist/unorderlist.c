#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node *start;

/* inserting element first in single linked list*/
int insert_first(int num) {
	struct node *new,*tmp;
	new = malloc(sizeof(struct node));
	
	if(!new) 
		return -1;
	new->data = num;
	new->next = NULL;

	if(!start) {
		
		start = new;
		return 0;
	}

	tmp =start;

	new->next = tmp;
	start = new;
}

/* inserting element last in single linked list*/
int insert_last(int num) {
	struct node *tmp,*new;
	new = malloc(sizeof(struct node));
	
	if(!new) 
		return -1;
	new->data = num;
	new->next = NULL;
	
	if(!start) {
		start = new;
		return 0;
	}
	
	tmp = start;
	
	while(tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = new;

	return 0;
}

/* delete element first in single linked list*/
void delete_first() {
	struct node *tmp;
	tmp = start;
	start = start->next;
	free(tmp);
}
/*delete element last in single linked list*/
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

/* find middle element in single linked list*/
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

/*reverse single linked*/
void reverse() {
	struct node *tmp=NULL,*prv;
	prv = start;
	while(prv) {
		prv = prv->next;
		start->next = tmp;
		tmp = start;
		if(prv)
			start = prv;
	}
} 

void print() {
	struct node *tmp;
	tmp = start;
	while(tmp) {
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
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
/*	a = mid_ele();
	printf("mid ele: %d\n",a);
*/
	return 0;
}
