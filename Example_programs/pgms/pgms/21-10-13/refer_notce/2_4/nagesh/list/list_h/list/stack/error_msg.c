#include "header.h"

#include <stdio.h>
int error_no;
void error_msg(char *s)
{

	switch(error_no)
	{

		case SUCCESS  : printf("%s success",s);
			break;

		case LISTEMPTY : printf("%s listempty",s);
			break;
		default : printf("%s memory not allocated",s);

			
	}



}
