#include<stdio.h>
#include<string.h>
#include"handle.h"
int canhandle(const char *name)
{
	int len;
	len = strlen(name);
	name = (name + len) - 3;
	if(!strcmp(name,"mp3")) {
		printf("the file %s can handle\n",name);
		return 1;
	}
	else {
		
		printf("the file %s cannot handle\n",name);
		return -1;
	}
}
void playmp3(const char *name)
{
	int ret;
	ret = canhandle(name);
	if(ret < 0) {
		printf("the file %s cannot play\n",name);
		return;
	}
	else {
		printf("the file %s can play\n",name);
		return;
	}
}

void convert(const char *name)
{
	int ret;
	char type[5];
	ret = canhandle(name);
	if(ret < 0) {
		printf("the file %s cannot convert\n",name);
		return;
	}
	else {

		printf("enter the type\n");
		scanf("%s",type);
		printf("the file %s can conert other format %s\n","mp3",type);
		return;
	}
}	
	
		
