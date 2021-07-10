#include<stdio.h>
#include<string.h>
#include"designheader.h"
int canhandle(const char *name) 
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

void drawimage(const char *name)
{
	int ret;
	ret = canhandle(name);
	if(ret < 0) 
		printf("cannot handle file %s\n",name);
	else
		printf("contents of  file %s\n",name);
}

void saveimage(const char *name) 
{
	int ret1;
	char type[5];
	ret1 = canhandle(name);
	if(ret1 < 0) 
		printf("cannot handle file %s\n",name);
	else {
		printf("enter image format convert");
		scanf("%s",&type);
		printf("converting from %s to %s image format\n","gif",type);
	}
}
	
	
