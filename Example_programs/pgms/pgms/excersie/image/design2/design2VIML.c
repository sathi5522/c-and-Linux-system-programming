#include<stdio.h>
#include<string.h>
#include"design2header.h"
struct imagehandler *handlers[] = {	&gifhandle,
					&tifhandle,
					&jpghandle,
					NULL
				  };

int findhandler(const char *name)
{
	int index =0,ret;
	for(;handlers[index];index++) {
		ret = handlers[index]->canhandle(name);
		if(ret == 1)
			return index;
	}
	return -1;
}

void vdrawimage(const char *name) 
{
	int ret;
	ret = findhandler(name);
	if(ret < 0) { 
		printf("cannot handle %s file\n",name);
		return;
	}
	handlers[ret]->drawimage(name);
	
}
void vsaveimage(const char *name) 
{
	int ret;
        ret = findhandler(name);
        if(ret < 0) { 
                printf("cannot handle %s file\n",name);
                return;
        }
        handlers[ret]->saveimage(name);
}

	

