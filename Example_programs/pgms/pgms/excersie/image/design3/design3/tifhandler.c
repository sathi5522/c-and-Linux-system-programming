#include<stdio.h>
#include<string.h>
#include"handlers.h"
int tifcanhandle(const char *name)
{

	int len;
	len = strlen(name);
	name = (name + len) - 3;
	if(!strcmp (name,"tif"))
		return 1;
	else 
		return -1;
}

void tifdisplayimage(const char *name)
{

	int ret;
	ret = tifcanhandle(name);
	if(ret < 0)
		printf("can not handle %s file\n",name);
	else
		printf("contents of the file %s\n",name);
}

void tifsaveimage(const char *name)
{

	int ret;
	char type[20];
	if(ret < 0)
		printf("can not handle %s file\n",name);

	else{
	printf("enter image format to convert\n");
	scanf("%s", type);
	printf("converting %s to %s image fomat\n","tif", type);
	}
}

struct imagehandler tifhandler = {tifcanhandle, tifdisplayimage, tifsaveimage};

int _init()
{
        reg_handler(&tifhandler);
        printf("registering the tifhandler\n");
}
int _fini()
{
        printf("unregistering the tifhandler\n");
}

