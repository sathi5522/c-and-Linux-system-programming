#include<stdio.h>
#include<string.h>
#include"handlers.h"


struct imagehandler *handlers[] = { &gifhandler, &tifhandler, &jpghandler, NULL};

int findhandler(const char *name)
{

	int index = 0, ret;
	for(;handlers[index];index++){
		ret = handlers[index] -> canhandle(name);
		if(ret == 1)
			return index;
		
	}
	return -1;	
}

void vdisplayimage(const char *name)
{

	int ret;
	
	ret = findhandler(name);
	if(ret < 0){
		printf("can not handle %s file\n",name);
		return;
	}
	
	handlers[ret] -> displayimage(name);
}

void vsaveimage(const char *name)
{

	
	int ret;
	
	ret = findhandler(name);
	if(ret < 0){
		printf("can not handle %s file\n",name);
		return;
	}

	handlers[ret] -> saveimage(name);
}
		

