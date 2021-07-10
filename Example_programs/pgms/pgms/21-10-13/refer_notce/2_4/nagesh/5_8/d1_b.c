#include <stdio.h>
#include <string.h>
int handle(char *han)
{
	int ret;
	ret = strcmp(((strlen(han)+han)-3),"gif");
	
}


void open(char *op)
{
	int ret;
	ret = handle(op);
	if(ret != 0)
		printf("we cannot handle\n");
	else{
	printf("file opened\n");
	}

}

void convert(char *con)
{

	int ret;
	ret = handle(con);

	if(ret != 0)
		printf("we cannot handle\n");

	else{
	
		printf("file converted");

		}
}
