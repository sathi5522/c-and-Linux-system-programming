#include<stdio.h>
#include"handlers.h"
#include<string.h>
int jpgcanhandle(const char *name)
{

	int len;
	len = strlen(name);
	name = (name + len) - 3;
	if(!strcmp (name,"jpg"))
		return 1;
	else 
		return -1;
}

void jpgdisplayimage(const char *name)
{

	int ret;
	ret = jpgcanhandle(name);
	if(ret < 0)
		printf("can not handle %s file\n",name);
	else
		printf("contents of the file %s\n",name);
}

void jpgsaveimage(const char *name)
{

	int ret;
	char type[20];
	if(ret < 0)
		printf("can not handle %s file\n",name);

	else{
	printf("enter image format to convert\n");
	scanf("%s", type);
	printf("converting %s to %s image fomat\n","jpg", type);
	}
}

struct imagehandler jpghandler = {jpgcanhandle, jpgdisplayimage,jpgsaveimage};
