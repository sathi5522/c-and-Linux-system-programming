#include "error.h"
#include <stdio.h>
int error_no;

void error_msg(char *s)
{

	switch(error_no)
	{

		case -1 : printf("%s:malloc failed",s);
				break;

		case 1 : printf("%s: first element is successully entered",s);
				break;
		case -2 : printf("%s: list is empty",s);
				break;

		default : printf("%s:success",s);
				
	}




}

