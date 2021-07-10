#include <stdio.h>
#include <string.h>
#include "d2.h"
int  gif_handle(char *han)
{
	int ret;
	ret = strcmp(((strlen(han)+han)-3),"gif");
	return ret;
}


void gif_open(char *op)
{
	int ret;
	ret = gif_handle(op);
	if(ret != 0){
		printf("we cannot handle\n");


			}
	else{
	printf("file opened\n");


	}

}

void  gif_convert(char *con)
{

	int ret;
	ret = gif_handle(con);

	if(ret != 0){
		printf("we cannot handle\n");

}
	else{
	
		printf("file converted");


		}
}

struct image gifhandle = {gif_handle, gif_open, gif_convert};





        
int _init()
{
        register_handle(&gifhandle);
        return 0;
}

int _fini()
{

        printf("gif unloaded\n");
        return 0;
}
