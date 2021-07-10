#include<stdio.h>

int main()
{
	char *str = "hai welcome to world";
	char *p;

	p = strstr(str,"to");
	printf("%s\n", p); 

	p = strstr(str,"hello");
	if(p==NULL)
	printf("p=NULL\n");
	else
	printf("p=%p\n",p); 
}
