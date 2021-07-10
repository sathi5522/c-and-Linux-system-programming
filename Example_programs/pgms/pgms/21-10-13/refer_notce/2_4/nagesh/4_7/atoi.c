#include <stdio.h>

unsigned int atoi(char *s)
{


	unsigned int  result = 0;
	char c;
        while(*s  != '\0'){
	//	printf("%c",*s);
		
		result = (result * 10)+((*s) - 0x30);
			s++;
			}
		
		printf("%d",result);
	return result;

}

int main()
{
	char r[] = "123";

	 atoi(r);

	return 0;

}
