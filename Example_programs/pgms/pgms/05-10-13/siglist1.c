#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node *next;
};



int insert_first(struct node **start,int arg)
{
        struct node *new,*tmp;
        new = malloc(sizeof(struct node));
        if(!new)
                return -1;

        new->data = arg;
        new->next = NULL;
        if(!(*start)) {
                *start  = new;
                return 0;
        }

        tmp = *start;

        new->next = tmp;
        *start = new;
}

int remove_dup(struct node **start)
{
    	struct node *p,*prev,*tmp;
    	p = (*start);

	while(p)
    	{
		prev = p;
		tmp = p->next;

		while(tmp) {
        		if(p->data==tmp->data)
        		{
          			prev->next = tmp->next;
          			free(tmp);
				tmp = prev->next;
        		}
			else{
			prev = tmp;
    			tmp = tmp->next;
			}
		}

       			 p=p->next;
		
   	}
		return 0;
}

int print(struct node **start)
{
        struct node *tmp;
        tmp = *start;
        while(tmp) {
                printf("%d\n",tmp->data);
                tmp = tmp->next;
        }
}
int main()
{
	struct node *start = NULL;
	insert_first(&start,10);
        insert_first(&start,20);
        insert_first(&start,10);
        insert_first(&start,40);

        print(&start);

        remove_dup(&start);
	print(&start);
        return 0;
}

