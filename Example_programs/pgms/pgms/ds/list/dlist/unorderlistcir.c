#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *next,*prev;
};

struct node *start;

/*insert first in circular double linked list*/
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
		new->next=start;
		new->prev=start;
		return 0;
	}
	tmp =start;
	while(tmp->next != start){
		tmp = tmp->next;
	}

	new->prev = tmp;
	new->next = start;
	start->prev = new;
	tmp->next = new;
	start = new;
}

/*insert last in circular double linked list*/
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
		new->next = start;	
		new->prev = start;
		return 0;
	}
	
	tmp = start;
	
	while(tmp->next != start) {
		tmp = tmp->next;
	}

	tmp->next = new;
	new->next = start;
	new->prev = tmp;
	start->prev = new;
	return 0;
}

/*delete first in circular double linked list*/
void delete_first() {
	struct node *tmp,*tmp1;
	tmp = start;
	tmp1 = start;
	while(tmp1->next != start) 
		tmp1 = tmp1->next;
	start = tmp->next;
	start->prev = tmp1;
	tmp1->next = start;
	free(tmp);
}

/*delete last in circular double linked list*/
int delete_last()
{
        struct node *tmp,*pre;
        tmp = start;
        while(tmp->next!=start) {
                pre = tmp;
                tmp = tmp->next;
        }
        pre->next = start;
        free(tmp);
}

/*find middle element in circular double linked list*/
int mid_ele() {
	struct node *seq,*alt;
	seq = start;
	alt = start;

	while(alt->next != start  && alt->next->next != start) {
		seq = seq->next;
		alt = alt->next->next;
	}
	return seq->data;

}

/*delete particular element in circular double linked list*/
int delete_ele(int num) {
        struct node *tmp,*prv,*tmp1;
        tmp = start;
	tmp1 = start;
	while(tmp1->next!=start) 
		tmp1 = tmp1->next;
        while(tmp->next!=start && (num != tmp->data)) {
                        prv = tmp;
                        tmp = tmp->next;

                }
        if(tmp == start) {
                start= tmp->next;
                start->prev = tmp->prev;
		tmp1->next = start;
                free(tmp);
                return 0;
        }

        else {
                if(tmp->next == start) {
                        prv->next = tmp->next;
                        free(tmp);
                }
                else {
                        prv->next = tmp->next;
                        tmp->next->prev = prv;
                        free(tmp);
                }
        }

        return 0;

}

/*delete duplicate element in circular double linked list*/
int delete_dup(int num) {
        struct node *tmp,*prv,*tmp1;
        tmp = start;
        while(tmp->next!=start) {
                prv = tmp;
                tmp1 = tmp->next;
                while(tmp1->next!=start) {
                        if(tmp->data != tmp1->data) {
                                prv = tmp1;
                                tmp1 = tmp1->next;
                        }
                        else {
                                if(tmp1->next == start) {
                                        prv->next = tmp1->next;
                                        free(tmp1);
                                }
                                else {
                                        prv->next = tmp1->next;
                                        tmp1->next->prev = prv;
                                        free(tmp1);
                                }
                        tmp1 = prv->next;
                        }
                }
        tmp=tmp->next;
        }


        return 0;
}


void print() {
	struct node *tmp,*cur;
	tmp = start;
	while(tmp->next != start) {

                printf("%d ",tmp->data);
                tmp = tmp->next;
        }
        printf("%d ",tmp->data);
        printf("\n");

        cur = tmp;
        while(cur->prev != start->prev) {
                printf("%d ",cur->data);
                cur = cur->prev;
        }
        printf("%d ",cur->data);
        printf("\n");

}


int main() {
	int a;

	insert_last(10);
	insert_last(50);
	insert_last(20);
	insert_last(10);
	insert_last(40);

	print();
	/*a = mid_ele();
	printf("mid ele :%d\n",a);*/
	/*reverse();
	print();*/
	/*delete_last();
	print();*/
	
	delete_ele(10);
	print();

	/*delete_dup(10);
	print();*/
	return 0;
}
