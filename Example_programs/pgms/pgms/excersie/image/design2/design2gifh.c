#include<stdio.h>
#include<string.h>
#include"design2header.h"
int gif_canhandle(const char *name) 
{
	int len;
	len = strlen(name);
	name = (name + len) -3;
	if(!strcmp(name,"gif")) {
		return 1;
	}
	else {
		return -1;
	}
}

void gif_drawimage(const char *name)
{
	int ret;
	ret = gif_canhandle(name);
	if(ret < 0) 
		printf("cannot handle file %s\n",name);
	else
		printf("contents of  file %s\n",name);
}

void gif_saveimage(const char *name) 
{
	int ret;
	char type[5];
	ret = gif_canhandle(name);
	if(ret < 0) 
		printf("cannot handle file %s\n",name);
	else {
		printf("enter image format convert");
		scanf("%s",type);
		printf("converting from %s to %s image format\n","gif",type);
	}
}
struct imagehandler gifhandle = {	gif_canhandle,
					gif_drawimage,
					gif_saveimage
				};	
	
