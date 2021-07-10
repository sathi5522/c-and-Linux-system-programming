#include<stdio.h>
#include<string.h>
#include"handlers.h"
int gifcanhandle(const char *name)
{

	int len;
	len = strlen(name);
	name = (name + len) - 3;
	if(!strcmp (name,"gif"))
		return 1;
	else 
		return -1;
}

void gifdisplayimage(const char *name)
{

	int ret;
	ret = gifcanhandle(name);
	if(ret < 0)
		printf("can not handle %s file\n",name);
	else
		printf("contents of the file %s\n",name);
}

void gifsaveimage(const char *name)
{

	int ret;
	char type[20];
	if(ret < 0)
		printf("can not handle %s file\n",name);

	else{
	printf("enter image format to convert\n");
	scanf("%s", type);
	printf("converting %s to %s image fomat\n","gif", type);	
	}
}

struct imagehandler gifhandler = { gifcanhandle, gifdisplayimage, gifsaveimage};
