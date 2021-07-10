#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *next;
};

struct node *start = NULL;
/* ascending order single linked list*/
int insert(int num) {
	
	struct node *new,*tmp,*prv;
	
	new = malloc(sizeof(struct node));

	if(!new) 
		return -1;

	new->data = num;
	new->next = NULL;	

	if(!start) {
                        start = new;
                        return 0;
        }


        if(new->data <= start->data) {
                new->next = start;
		start = new;
                /*tmp = start;
                while(tmp->next!=NULL)
                        tmp=tmp->next;
                start = new;
                tmp->next= NULL;*/

        }
        else {
                tmp =start;
                while(tmp->next !=NULL && new->data > tmp->data) {
                        prv = tmp;
                        tmp = tmp->next;
                }
                if(new->data >= tmp->data) {
                        tmp->next = new;
                        new->next = NULL;
                }
                else {
                        prv->next = new;
                        new->next = tmp;
                }
        }

	return 0;
}

/* descending order in single linked list*/
int deinsert(int num) {

        struct node *new,*tmp,*prv;

        new = malloc(sizeof(struct node));

        if(!new)
                return -1;

        new->data = num;
        new->next = NULL;

	if(!start) {
                  start = new;
                  return 0;
        }


        if(new->data >= start->data) {
                new->next = start;
                start = new;
                /*tmp = start;
                while(tmp->next!=NULL)
                        tmp=tmp->next;
                start = new;
                tmp->next= NULL;*/

        }
        else {
                tmp =start;
                while(tmp->next !=NULL && new->data < tmp->data) {
                        prv = tmp;
                        tmp = tmp->next;
                }
                if(new->data <= tmp->data) {
                        tmp->next = new;
                        new->next = NULL;
                }
                else {
                        prv->next = new;
                        new->next = tmp;
                }
        }

        return 0;
}

/*delete a particular element single linked list*/
int dlete_ele(int num) {
	struct node *tmp,*prv;
	tmp = start;

	while(tmp && (num != tmp->data)) {
			prv = tmp;
			tmp = tmp->next;

		}
	
	if(tmp == start) {
		start = tmp->next;
		free(tmp);	
		return 0;
	}
	prv->next = tmp->next;
	free(tmp);

	return 0;
	
}

/*delete duplicate elements in single linked list*/ 
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
				
				prv->next = tmp1->next;
				free(tmp1);
				tmp1 = prv->next;
			}
		}
	tmp=tmp->next;
	}


	return 0;
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

	deinsert(70);
	deinsert(30);
	deinsert(70);
	deinsert(5);
	deinsert(90);

	print();

	//delete_dup(30);
	//print();
	return 0;
}
	
	
