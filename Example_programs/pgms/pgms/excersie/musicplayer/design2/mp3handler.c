#include<stdio.h>
#include<string.h>
#include"handler.h"

int mp3canhandle(const char *name)
{
	int len;
	len = strlen(name);
	name = (name + len) - 3;
	if(!strcmp(name,"mp3")) 
		return 1;
	else 
		return -1;
}
void mp3play(const char *name)
{
	int ret;
	ret = mp3canhandle(name);
	if(ret < 0) {
		printf("the file %s cannot play\n",name);
		return;
	}
	else {
		printf("the file %s can play\n",name);
		return;
	}
}

void mp3convert(const char *name)
{
	int ret;
	char type[5];
	ret = mp3canhandle(name);
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
	
struct playhandler mp3handler = {
                                        mp3canhandle,
                                        mp3play,
                                        mp3convert
                                };

		
