#include<stdio.h>

int atoi(char *s)
{
	int i = 0,p = 0;
	for(;*s;i++) {
		p = p * 10 + (*s - '0');
		s++;
	}
	return p;
}

int main()
{

	char s[] = "123";
	int c;
	c = atoi(s);
	printf("%d\n",c);

	return 0;

}
