#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node *start;

/*insert first in single circular linked list*/
int insert_first(int num) {
	struct node *new,*tmp;
	new = malloc(sizeof(struct node));
	
	if(!new) 
		return -1;
	new->data = num;
	new->next = NULL;

	if(!start) {
		start = new;
		new->next=start;
		return 0;
	}
	tmp =start;
	while(tmp->next != start){
		tmp = tmp->next;
	}


	new->next = start;
	tmp->next = new;
	start = new;
}

/*inserting last in single circular linked list*/
int insert_last(int num) {
	struct node *tmp,*new;
	new = malloc(sizeof(struct node));
	
	if(!new) 
		return -1;
	new->data = num;
	new->next = NULL;
	
	if(!start) {
		start = new;
		start->next = start;	
		return 0;
	}
	
	tmp = start;
	
	while(tmp->next != start) {
		tmp = tmp->next;
	}

	tmp->next = new;
	new->next = start;

	return 0;
}

/*delete first in single circular linked list*/
void delete_first() {
	struct node *tmp,*tmp1;
	tmp = start;
	tmp1 = start;
	while(tmp1->next!=start)
		tmp1 = tmp1->next;
	start = tmp->next;
	tmp1->next= start;
	free(tmp);
}

/*delete last in single circular linked list*/
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

/*find middle element in single circular linked list*/
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

/*reverse single circular linked list*/
void reverse() {
	struct node *tmp,*prv;
	prv = start;
	tmp = start;
	while(tmp->next != start) 
		tmp = tmp->next;
	while(prv->next != start) {
		prv = prv->next;
		start->next = tmp;
		tmp = start;
		if(prv->next!=start)
			start = prv;
	}
} 

/*delete particular element in single circular linked list*/
int delete_ele(int num) {
        struct node *tmp,*prv,*tmp1;
        tmp = start;
	tmp1 = start;
	while(tmp1->next != start)
		tmp1 = tmp1->next;

        while(tmp && (num != tmp->data)) {
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

	
	/*tmp = start;
        do {
               		printf("%d\n",tmp->data);
                	tmp = tmp->next;
		}while(tmp != start);
	*/

}


int main() {
	int a;

	insert_last(10);
	insert_last(50);
	insert_last(20);
	insert_last(10);
	insert_last(40);

	print();
	delete_ele(10);
	print();
	/*a = mid_ele();
	printf("mid ele :%d\n",a);
	reverse();
	print();
	delete_last();
	print();

	delete_ele(50);
	print();*/

	/*delete_dup(10);
	print();*/
	return 0;
}
