#include<stdio.h>
#include<string.h>
#include"designheader.h"
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
		else 	
		handlemenuevent(ch);
	}

	
}
void handlemenuevent(char ch1)
{
	char name[30];
	printf("enter the file name\n");
	scanf("%s",&name);
	switch(ch1) {
		case 1:
			drawimage(name);
			break;

		case 2:
			saveimage(name);
			break;

		default:
			printf("Enter the correct choice\n");
	}
}

int main() 
{
	displaymenu();
	return 0;
}


			
