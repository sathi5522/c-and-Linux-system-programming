#include<stdio.h>
#include<string.h>
#include"handler.h"

void handlemenu(int ch)
{
	char name[30];
	printf("enter the file name\n");
	scanf("%s",name);
	switch(ch) {
		case 1:
			vplay(name);
			return;
		case 2:
			vconvert(name);
			return;
		default:
			printf("enter the correct option\n");
	}
	
}
void displaymenu() 
{
	int ch;
	while(1) {
		printf("1.playmp3\n");
		printf("2.convert\n");
		printf("3.exit\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		if(ch == 3)
			break;
		handlemenu(ch);
	}
	
}

int main()
{
	displaymenu();

	return 0;
}
