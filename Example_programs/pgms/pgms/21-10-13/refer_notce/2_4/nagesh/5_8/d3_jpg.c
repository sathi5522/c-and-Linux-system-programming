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
//			return ret;
		}
	else{
	printf("cannot implemented\n");
//		return 0;
	}

}

void jpg_convert(char *con)
{

	int ret;
	ret = jpg_handle(con);

	if(ret == 0){
		printf("file converted\n");
//			return ret;
			}
	else{
	
		printf("cannot implement");
//		return 0;
		}

}

struct image jpghandle = {jpg_handle,jpg_open,jpg_convert};
