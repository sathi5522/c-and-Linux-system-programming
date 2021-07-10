#include<stdio.h>
#include<string.h>
	struct msg {
		char str[30];
	};
char fun(struct msg *y,char *x,int y1) 
{
	int i = 0;
	for(i=0;i<y1;i++){
	if(!strcmp(y[i].str,x))
		return 1;
	}
		return 0;
	
}
	
int main()
{

	struct msg x[5] = {"hello","hai","world","hello world","hai world"};
	int z;
	z = fun(x,"world",5);
	printf("%d\n",z);


	return 0;
}
