#include<stdio.h>

int main()
{
	struct msg {
		char str[20];
		int len;
	};
	struct msg x;
	x.str[0] = 'h'; 
	x.str[1] = 'e'; 
	x.str[2] = 'l'; 
	x.str[3] = 'l'; 
	x.str[4] = 'o';
	x.str[5] = '\0'; 
	int i = 0;
	for(;x.str[i] != '\0';i++);
	x.len = i;
	printf("%d\n",x.len);
	
	return 0;
}
