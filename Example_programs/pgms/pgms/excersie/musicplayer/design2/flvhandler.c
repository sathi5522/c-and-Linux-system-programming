#include<stdio.h>
#include<string.h>
#include"handler.h"

int flvcanhandle(const char *name)
{
	int len;
	len = strlen(name);
	name = (name + len) - 3;
	if(!strcmp(name,"flv")) 
		return 1;
	
	else 
		
		return -1;
	
}
void flvplay(const char *name)
{
	int ret;
	ret = flvcanhandle(name);
	if(ret < 0) {
		printf("the file %s cannot play\n",name);
		return;
	}
	else {
		printf("the file %s can play\n",name);
		return;
	}
}

void flvconvert(const char *name)
{
	int ret;
	char type[5];
	ret = flvcanhandle(name);
	if(ret < 0) {
		printf("the file %s cannot convert\n",name);
		return;
	}
	else {

		printf("enter the type\n");
		scanf("%s",type);
		printf("the file %s can conert other format %s\n","flv",type);
		return;
	}
}

struct playhandler flvhandler = {
					flvcanhandle,
					flvplay,
					flvconvert
				};	
	
		
