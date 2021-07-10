#include "header.h"
#include <stdio.h>
int error_no;
void error_msg(char *s)
{

	switch(error_no){

	case MALLOC_FAILED : printf("%s:malloc faield\n",s);
				break;

	case EMPTYLIST    : printf("%s:emptylist\n",s);
				break;
	
	default       : printf("%s:success\n",s);
			
	}



}
