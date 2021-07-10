#include<stdio.h>
#include<string.h>
int main()
{
	struct msg {
		char str[30];
		int len;
	};
	struct msg x = {"veda solutions"};
	
	x.len = strlen(x.str);
	struct msg *p = &x;
	struct msg **q = &p;
	strcpy((*q)->str,"pointer to struct");
	x.len = strlen((*q)->str); 

	//y.len = x[1].len;
	printf("%s %d \n",(*q)->str,x.len);

	return 0;
}
