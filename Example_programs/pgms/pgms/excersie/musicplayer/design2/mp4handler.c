#include<stdio.h>
#include<string.h>
#include"handler.h"

int mp4canhandle(const char *name)
{
	int len;
	len = strlen(name);
	name = (name + len) - 3;
	if(!strcmp(name,"mp4")) 
		return 1;
	
	else 
		
		return -1;
	
}
void mp4play(const char *name)
{
	int ret;
	ret = mp4canhandle(name);
	if(ret < 0) {
		printf("the file %s cannot play\n",name);
		return;
	}
	else {
		printf("the file %s can play\n",name);
		return;
	}
}

void mp4convert(const char *name)
{
	int ret;
	char type[5];
	ret = mp4canhandle(name);
	if(ret < 0) {
		printf("the file %s cannot convert\n",name);
		return;
	}
	else {

		printf("enter the type\n");
		scanf("%s",type);
		printf("the file %s can conert other format %s\n","mp4",type);
		return;
	}
}	
	
struct playhandler mp4handler = {
                                        mp4canhandle,
                                        mp4play,
                                        mp4convert
                                };

		
