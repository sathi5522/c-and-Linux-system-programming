#include <stdio.h>
#include "d2.h"





//struct image *ih[]= {&gifhandle, &tifhandle, &jpghandle,NULL};


 
int v_handle(char *han)
{
	int index  = 0,ret=0;
	for(; index<no_lib;index++){
	//	printf("%d",no_lib);	
		ret = ih[index]->handle(han);
		if(ret == 0)
			return index;
		}
	
//	printf("%d",no_lib);
	return -1;
}


void v_open(char *op)
{

	int ret;
	ret = v_handle(op);
	if(ret == -1)
		printf("unable to handle");
	else{	
	ih[ret]->open(op);
	}
}

void v_convert(char *conv)
{
	

  int ret;
        ret = v_handle(conv);
        if(ret == -1)   
                printf("unable to handle");
         else{   
        ih[ret]->convert(conv);
	}
}
