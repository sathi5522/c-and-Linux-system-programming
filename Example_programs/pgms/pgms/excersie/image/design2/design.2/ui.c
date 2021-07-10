#include<stdio.h>
#include<string.h>
#include"handlers.h"
void handlemenu(int ch)
{

	char name[50];
	printf("enter file name\n");
	scanf("%s",name);
	
	switch(ch){
		
		case 1 :
			 vdisplayimage(name);
			 return;

		case 2 :
			 vsaveimage(name);
			 return;
		default:
			printf("plz enter correct option\n");
		}

}

void displaymenu(void)

{

	int ch;
	while(1){
		printf("1.show image\n");
		printf("2.draw image\n");
		printf("3.exit\n");
		printf("enter ch\n");
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
