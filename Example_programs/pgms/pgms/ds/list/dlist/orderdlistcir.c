#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start = NULL;

/*insert ascending order in circular double linked list*/
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
			new->next = start;
			new->prev = start;
                        return 0;
        }


        if(new->data <= start->data) {
                new->next = start;
		start->prev=new;
		tmp = start;
                while(tmp->next!=start)
                        tmp=tmp->next;
		start = new;
		start->prev = tmp;
		tmp->next = start;
        }
        else {
                tmp =start;
                while(tmp->next !=start && new->data > tmp->data) {
                        prv = tmp;
                        tmp = tmp->next;
                }
                if(new->data >= tmp->data) {
                        tmp->next = new;
			new->prev = tmp;
                        new->next = start;
			start->prev = new;
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

/*inserting descending order in circular double linked list*/
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
		new->next = start;
                new->prev = start;
                  return 0;
        }


        if(new->data >= start->data) {
		new->next = start;
                start->prev=new;
                tmp = start;
                while(tmp->next!=start)
                        tmp=tmp->next;
                start = new;
                start->prev = tmp;
                tmp->next = start;
        }
        else {
                tmp =start;
                while(tmp->next !=start && new->data < tmp->data) {
                        prv = tmp;
                        tmp = tmp->next;
                }
                if(new->data <= tmp->data) {
                	tmp->next = new;
                        new->prev = tmp;
                        new->next = start;
                        start->prev = new;
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

/*delete particular element in circular double linked list*/
int dlete_ele(int num) {
	struct node *tmp,*prv,*tmp1;	
	tmp = start;
	tmp1 = start;
	while(tmp1->next != start)
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

/* delete duplicate element in circular double linked list*/
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
	struct node *tmp,*cur,*tmp1;
	tmp = start;
	tmp1 = start;
	
	while(tmp->next != start) {

		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("%d ",tmp->data);
	printf("\n");
	
	cur = tmp;
	while(cur->prev != tmp1->prev) {
		printf("%d ",cur->data);
		cur = cur->prev;
	}
	printf("%d ",cur->data);
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

	deinsert(90);
	deinsert(30);
	deinsert(70);
	deinsert(5);
	deinsert(90);
	//deinsert(80);
	//deinsert(100);

	//print_first();
	//print_last();
	print();
	dlete_ele(70);
	print();
	/*delete_dup(90);
	print();*/
	return 0;
}
	
	
