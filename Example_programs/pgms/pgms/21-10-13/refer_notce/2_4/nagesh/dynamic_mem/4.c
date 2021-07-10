#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct msg str_t;
struct msg {
		int i;
		char name[20];
		str_t *q;
		};

int main()
{

	str_t *p;

	p = malloc(sizeof(str_t));
	if(!p)
	{
		perror("malloc");
		exit(1);
	}
	
	p->q = malloc(sizeof(str_t));
	if(!(p->q))
        {
                perror("malloc");
                exit(1);
        }


	p->i = 20;
	strcpy(p->name , "nagesh");

	printf("%d%s\n",p->i,p->name);

	(p->q)->i = 40;
	strcpy((p->q)->name,"ganesh");

	printf("%d%s\n",(p->q)->i,(p->q)->name); 
	
	


		free(p->q);
		free(p);
	return 0;
	

}
