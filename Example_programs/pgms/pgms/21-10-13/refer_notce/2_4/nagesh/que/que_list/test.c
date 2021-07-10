#include <stdio.h>
#include <stdlib.h>

typedef struct msg que_t;
struct msg{

	int val;
	que_t *next;

	};

int insert_first(que_t **q, int num)

{
	int ret;
	que_t *tmp;
	tmp = 	*q;
	tmp = malloc(sizeof(que_t));
	if(!tmp)
	{
		perror("malloc:");
		exit(1);
	}

	tmp->val = num;
	tmp->next = NULL;
	
	return 0;


}

int main()
{

	que_t *start = NULL;

	insert_first(&start,10);

	printf("val:%d\n",start->val);
	free(start);
	return 0;
}

