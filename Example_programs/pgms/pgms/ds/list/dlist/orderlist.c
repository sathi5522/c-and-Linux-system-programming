#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start = NULL;

/*insert ascending ordrer in double linked list*/
int insert(int num) {
	
	struct node *new,*tmp,*prv;
	
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


        if(new->data <= start->data) {
                new->next = start;
		start->prev=new;
		start = new;
        }
        else {
                tmp =start;
                while(tmp->next !=NULL && new->data > tmp->data) {
                        prv = tmp;
                        tmp = tmp->next;
                }
                if(new->data >= tmp->data) {
                        tmp->next = new;
			new->prev = tmp;
                        new->next = NULL;
                }
                else {
                        prv->next = new;
			new->prev = prv;
                        new->next = tmp;
			tmp->prev = new;
                }
        }

	return 0;
}

/*inserting descending order in double linked list*/
int deinsert(int num) {

        struct node *new,*tmp,*prv;

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


        if(new->data >= start->data) {
                new->next = start;
		start->prev = new;
                start = new;
        }
        else {
                tmp =start;
                while(tmp->next !=NULL && new->data < tmp->data) {
                        prv = tmp;
                        tmp = tmp->next;
                }
                if(new->data <= tmp->data) {
                        tmp->next = new;
			new->prev = tmp;
                        new->next = NULL;
                }
                else {
                        prv->next = new;
			new->prev = prv;
                        new->next = tmp;
			tmp->prev = new;
                }
        }

        return 0;
}

/*delete particulr element in double linked list*/

int dlete_ele(int num) {
	struct node *tmp,*prv;
	tmp = start;

	while(tmp && (num != tmp->data)) {
			prv = tmp;
			tmp = tmp->next;

		}
	
	if(tmp == start) {
		start = tmp->next;
		start->prev = NULL;
		free(tmp);	
		return 0;
	}
	if(tmp->next == NULL) {
		prv->next = tmp->next;
		free(tmp);
	}
	else {
		prv->next = tmp->next;
		tmp->next->prev = prv;
		free(tmp);
	}

	return 0;
	
}

/*delete duplicate in double linked list*/
int delete_dup(int num) {
	struct node *tmp,*prv,*tmp1;
	tmp = start;
	while(tmp) {
		prv = tmp;
		tmp1 = tmp->next;
		while(tmp1) {
			if(tmp->data != tmp1->data) {
				prv = tmp1;
				tmp1 = tmp1->next;
			}
			else {
				if(tmp1->next == NULL) {	
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


/*int print_first()
{
	struct node *tmp;
	tmp = start;

	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return 0;
}

int print_last()
{
	struct node *tmp;
	tmp = start;

	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->prev;
	}
	printf("\n");
	return 0;
}
*/
int main() {

	insert(90);
	insert(30);
	insert(70);
	insert(5);
	insert(90);
	insert(80);

	//print_first();
	//print_last();

	//delete_dup(30);
	print();
	dlete_ele(5);
	print();
	return 0;
}
	
	
