#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct msg {
		int i;
		char name[20];
		};
typedef struct msg str_t;

int main()
{

	str_t *p;

	p = malloc(sizeof(str_t));
	if(!p)
	{
		perror("malloc");
		exit(1);
	}

	p->i = 20;
	strcpy(p->name , "nagesh");

	printf("%d%s",p->i,p->name);

	free(p);
	return 0;
	

}
