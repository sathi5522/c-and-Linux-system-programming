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
//		return ret;
		}

	else{
	printf("not implement\n");
//	return 0;
	}

}

void tif_convert(char *con)
{

	int ret;
	ret = tif_handle(con);

	if(ret == 0){
		printf("file convered\n");
//			return ret;
			}
	else{
	
		printf("cannot implementd");
//		return 0;
		}

}

struct image tifhandle = {tif_handle,tif_open,tif_convert};
