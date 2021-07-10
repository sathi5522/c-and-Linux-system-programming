#include <stdio.h>
#include <string.h>
#include "d2.h"
int jpg_handle(char *han)
{
	int ret;
	ret = strcmp(((strlen(han)+han)-3),"jpg");

	return ret;
}


void jpg_open(char *op)
{
	int ret;
	ret = jpg_handle(op);
	if(ret == 0){
		printf("file opened\n");

		}
	else{
	printf("cannot implemented\n");

	}

}

void jpg_convert(char *con)
{

	int ret;
	ret = jpg_handle(con);

	if(ret == 0){
		printf("file converted\n");

			}
	else{
	
		printf("cannot implement");

		}

}

struct image jpghandle = {jpg_handle,jpg_open,jpg_convert};


int _init()
{

	register_handle(&jpghandle);
	return 0;
}

int _fini()
{
	printf("jpgunloaded\n");
	return 0;
}
