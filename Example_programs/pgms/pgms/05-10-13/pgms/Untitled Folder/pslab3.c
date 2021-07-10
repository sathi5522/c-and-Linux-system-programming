#include<stdio.h>
#include<string.h>
int *rollnum(int *l,int z)
{
	 *l = z;
}
char *str(char *q,char *r)
{
	strcpy(q,r);
}
char *grade(char *f,char h)
{
	*f=h;
}
int main()
{
	struct x {
		int rollnum;
		char str[20];
		char grade;
	};
	struct x  y = {10,"sathi",'a'};
	printf("%d %s %c \n",y.rollnum,y.str,y.grade);
	rollnum(&y.rollnum,20);
	printf("%d\n",y.rollnum);
	str(y.str,"satheesh");
	printf("%s\n",y.str);
	grade(&y.grade,'b');
	printf("%c\n",y.grade);
	printf("%d\n",y.rollnum);
	printf("%s\n",y.str);
	printf("%c\n",y.grade);
	

	return 0;
}

