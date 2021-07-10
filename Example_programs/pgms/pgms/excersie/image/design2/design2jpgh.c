#include<stdio.h>
#include<string.h>
#include"design2header.h"
int jpg_canhandle(const char *name) 
{
	int len;
	len = strlen(name);
	name = (name + len) -3;
	if(!strcmp(name,"jpg")) {
		return 1;
	}
	else {
		return -1;
	}
}

void jpg_drawimage(const char *name)
{
	int ret;
	ret = jpg_canhandle(name);
	if(ret < 0) 
		printf("cannot handle file %s\n",name);
	else
		printf("contents of  file %s\n",name);
}

void jpg_saveimage(const char *name) 
{
	int ret;
	char type[5];
	ret = jpg_canhandle(name);
	if(ret < 0) 
		printf("cannot handle file %s\n",name);
	else {
		printf("enter image format convert");
		scanf("%s",type);
		printf("converting from %s to %s image format\n","jpg",type);
	}
}

struct imagehandler jpghandle = {       jpg_canhandle,
                                        jpg_drawimage,
                                        jpg_saveimage
                                };	
	
