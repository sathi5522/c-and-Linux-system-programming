#include "header.h"
#include <stdio.h>
int error_no;
void error_msg(char *s)
{

	switch(error_no){

		case SUCCESS       :     printf("%s: successfully inserted",s);
				         break;

		case MALLOC_FAILED :     printf("%s: memory allocation is failed",s);
					 break;

		case LIST_EMPTY    :     printf("%s: list is empty",s);
				        	break;


		default   :           printf("%s: element is not found",s);
					
		}



}

