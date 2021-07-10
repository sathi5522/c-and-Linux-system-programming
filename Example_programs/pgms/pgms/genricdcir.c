#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <unistd.h>
struct node {
	void *data;
	struct node *next,*prev;
};

struct msg {
	int a;
	char name[20];
};

struct node *start = NULL;

void disp(struct node *p)
{

	
        struct msg *da;
        da = p->data;

        printf("%d %s\n", da->a, da->name );
}

void display(void (*fp)(struct node *))
{
	struct node *p;
	p = start;
        while(p->next != start) {
                (*fp)(p);
                p = p->next;

        }
	(*fp)(p);
}


int insert_first(void *num) {
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




int main() {

	struct msg *m=NULL;
	 
	m = malloc(sizeof(struct msg));
        if(m < 0){

                perror("malloc1");
                exit(1);
        }

	m->a = 10;
	strcpy(m->name,"sathi");
	insert_first(m);
	 
	m = malloc(sizeof(struct msg));
        if(m < 0){

                perror("malloc1");
                exit(1);
        }

	m->a = 20;
	strcpy(m->name,"satheesh");
	insert_first(m);
	
	m = malloc(sizeof(struct msg));
        if(m < 0){

                perror("malloc1");
                exit(1);
        }

	m->a = 30;
	strcpy(m->name,"nelavalli");
	insert_first(m);

	display(disp);
	return 0;
}	
