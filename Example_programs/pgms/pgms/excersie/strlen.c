#include<stdio.h>

unsigned int my_strlen(const char *p)
{

	int i = 0;
	for(; p[i] !='\0';i++);
	
	return i; 
}

int main()
{

	char str[] = "welcome to world";
	int a;
	a = my_strlen(str);
	printf("%d\n",a);

	return 0;
	
}
