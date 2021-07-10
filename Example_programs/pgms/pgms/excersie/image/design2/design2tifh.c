#include<stdio.h>
#include<string.h>
#include"design2header.h"
int tif_canhandle(const char *name) 
{
	int len;
	len = strlen(name);
	name = (name + len) -3;
	if(!strcmp(name,"tif")) {
		return 1;
	}
	else {
		return -1;
	}
}

void tif_drawimage(const char *name)
{
	int ret;
	ret = tif_canhandle(name);
	if(ret < 0) 
		printf("cannot handle file %s\n",name);
	else
		printf("contents of  file %s\n",name);
}

void tif_saveimage(const char *name) 
{
	int ret;
	char type[5];
	ret = tif_canhandle(name);
	if(ret < 0) 
		printf("cannot handle file %s\n",name);
	else {
		printf("enter image format convert");
		scanf("%s",type);
		printf("converting from %s to %s image format\n","tif",type);
	}
}
struct imagehandler tifhandle = {       tif_canhandle,
                                        tif_drawimage,
                                        tif_saveimage
                                };	
	
