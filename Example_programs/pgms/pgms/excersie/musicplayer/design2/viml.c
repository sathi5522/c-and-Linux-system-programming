#include<stdio.h>
#include<string.h>
#include"handler.h"
struct playhandler *handlers[] = {
					&mp3handler,
					&mp4handler,
					&flvhandler,
					NULL
				  };
int findhandler(const char *name)
{
	int index,ret;
	index =0;
	for(;handlers[index];index++) {
		ret = handlers[index]->canhandle(name);
		if(ret == 1)
			return index;
	}
	return -1;
}
void vplay(const char *name)
{
	int ret;
	ret = findhandler(name);
	if(ret < 0) {
		printf("the file %s cannot handle\n",name);
		return;
	}
	handlers[ret]->play(name);
}

void vconvert(const char *name)
{
	int ret;
	ret = findhandler(name);
	if(ret < 0) {
		printf("the file %s cannot handle\n",name);
		return;
	}
	handlers[ret]->convert(name);
}	
	
		
