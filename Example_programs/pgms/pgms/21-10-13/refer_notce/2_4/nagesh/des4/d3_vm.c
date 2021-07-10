#include <stdio.h>
#include "d2.h"
void loader(char *);


/*extern struct image gifhandle;
extern struct image tifhandle;
extern struct image jpghandle;

struct image *ih[]= {&gifhandle, &tifhandle, &jpghandle,NULL};*/


 
int v_handle(char *han)
{
	int index  = 0,ret=50;
	for(; index<no_lib;index++){
	//	printf("index %dret  %d",index,ret);
		ret = ih[index]->handle(han);
		if(ret == 0)
			return index;
		}

	return -1;
}


void v_open()
{

	int ret;

	char name[20];
	printf("enter file name\n");
	scanf("%s",name);	



	loader(name);
	ret = v_handle(name);
	if(ret == -1)
		printf("unable to handle");
	else{	
	ih[ret]->open(name);
	}
}

void v_convert()
{
	

  int ret;
	char name[20];
	printf("enter file name\n");
	scanf("%s",name);	
        ret = v_handle(name);
        if(ret == -1)   
                printf("unable to handle");
         else{   
        ih[ret]->convert(name);
	}
}
