#include <stdio.h>
#include <string.h>
#include "d2.h"
int tif_handle(char *han)
{
	int ret;
	ret = strcmp(((strlen(han)+han)-3),"tif");
	return ret;	
}


void tif_open(char *op)
{
	int ret;
	ret = tif_handle(op);
	if(ret == 0){
		printf("file opened\n");

		}

	else{
	printf("not implement\n");

	}

}

void tif_convert(char *con)
{

	int ret;
	ret = tif_handle(con);

	if(ret == 0){
		printf("file convered\n");

			}
	else{
	
		printf("cannot implementd");

		}

}

struct image tifhandle = {tif_handle,tif_open,tif_convert};

int _init()
{
	register_handle(&tifhandle);
	return 0;
}

int _fini()
{

	printf("tif unloaded\n");
	return 0;
}







