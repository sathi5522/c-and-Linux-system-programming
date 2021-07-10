#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *next;
};

struct node *start = NULL;

/*insert ascending order single circular linked list*/
int insert(int num) {
	
	struct node *new,*tmp,*prv;
	
	new = malloc(sizeof(struct node));

	if(!new) 
		return -1;

	new->data = num;
	new->next = NULL;
	if(!start) {
			start = new;
			new->next = start;
			return 0;
	}


	if(new->data <= start->data) {
		new->next = start;
		tmp = start;
		while(tmp->next!=start)
			tmp=tmp->next;
		start = new;
		tmp->next= start;
		
	}
	else {
		tmp =start;
		while(tmp->next !=start && new->data > tmp->data) {
			prv = tmp;
			tmp = tmp->next;
		}
		if(new->data >= tmp->data) {
			tmp->next = new;
			new->next = start;
		}
		else {
			prv->next = new;
			new->next = tmp;
		}
	}	

			
	return 0;
}

/* inserting descending order single circular linked list*/
int deinsert(int num) {

        struct node *new,*tmp,*prv;

        new = malloc(sizeof(struct node));

        if(!new)
                return -1;

	new->data = num;
        new->next = NULL;

        if(!start) {
                        start = new;
                        new->next = start;
                        return 0;
        }


        if(new->data >= start->data) {
                new->next = start;
                tmp = start;
                while(tmp->next!=start)
                        tmp=tmp->next;
                start = new;
                tmp->next= start;

        }
        else {
                tmp =start;
                while(tmp->next !=start && new->data < tmp->data) {
                        prv = tmp;
                        tmp = tmp->next;
                }
                if(new->data <= tmp->data) {
                        tmp->next = new;
                        new->next = start;
                }
                else {
                        prv->next = new;
                        new->next = tmp;
                }
        }


        return 0;
}
/*delete particular element in single circular linked list*/
int dlete_ele(int num) {
	struct node *tmp,*prv,*tmp1;
	tmp = start;
	tmp1 = start;
	while(tmp1->next!=start)
		tmp1=tmp1->next;
	while(tmp->next!=start && (num != tmp->data)) {
			prv = tmp;
			tmp = tmp->next;

		}
	
	if(tmp == start) {
		start = tmp->next;
		tmp1->next = start;
		free(tmp);	
		return 0;
	}
	prv->next = tmp->next;
	free(tmp);

	return 0;
	
}

/*delete duplicate element in single circular linked list*/
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
	while(tmp->next != start) {
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n",tmp->data);
	
	/*do {
               	printf("%d\n",tmp->data);
                tmp = tmp->next;
	}while(tmp != start);*/
}


int main() {

	deinsert(70);
	deinsert(30);
	deinsert(70);
	deinsert(5);
	deinsert(3);

	print();

	//dlete_ele(30);
	dlete_ele(70);
	print();
	return 0;
}
	
	
