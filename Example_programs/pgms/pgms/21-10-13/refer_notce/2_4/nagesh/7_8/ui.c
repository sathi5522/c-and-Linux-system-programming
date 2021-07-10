#include<stdio.h>
#include"head.h"

void  displaymenu()
{
	char name[10];
	int ch;
	while(1){
	printf("1.play a song\n");
	printf("2.convert foramat\n");
	printf("3.exit");

	printf("enter ur choice\n");
	scanf("%d",&ch);	

	switch(ch){

	case 1: printf("enter file name");
		scanf("%s",name);
		play_mp3(name);
		break;

	case 2: convert_mp3(name);
		break;

	case 3: exit(1);
		break;

	default :printf("choose correct option\n");
		break;
	}
}
}
	
int main()
{
	displaymenu();
	return 0;
}











