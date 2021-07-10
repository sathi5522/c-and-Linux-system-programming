#include<stdio.h>
#include<string.h>
#include"design2header.h"

void handlemenuevent(int ch1)
{
	char name[30];
	printf("enter the file name\n");
	scanf("%s",name);
	switch(ch1) {
		case 1:
			vdrawimage(name);
			return;

		case 2:
			vsaveimage(name);
			return;

		default:
			printf("Enter the correct choice\n");
	}
}

void displaymenu(void)
{
	int ch;
	while(1) {
		printf("1.show image\n");
		printf("2.convert image\n");
		printf("3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
	
		if(ch ==3)
			break;
		 	
		handlemenuevent(ch);
	}

	
}

int main() 
{
	displaymenu();
	printf("%x\n",&gifhandle);
	printf("%x\n",&tifhandle);
	printf("%x\n",&jpghandle);
	return 0;
}


			
