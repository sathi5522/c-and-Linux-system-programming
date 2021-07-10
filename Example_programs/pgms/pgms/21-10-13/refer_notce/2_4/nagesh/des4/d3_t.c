#include <stdio.h>
#include "d2.h"
//void loader();
void displaymenu()
{
//	char name[10];
	int ch;
	
	
//	printf("enter file name");
//	scanf("%s",name);
	while(1){
	printf("1. open  a file\n");
	printf("2. covert a file\n");
	printf("3. exit");
	
	printf("enter ur choice:\n");
	scanf("%d",&ch);
	
	
	switch(ch){

	case 1:  v_open();
		break;
	case 2: v_convert();
		break;
	case 3: goto x;
	
	default : printf("choose valid option\n");
	}
}
x : printf("exit");
}





int main()
{

// loader();
 displaymenu();
}
