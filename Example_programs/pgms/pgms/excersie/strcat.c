
#include<stdio.h>

char *my_strcat(char *dest,const char *src)
{
	char *p = dest;
	
	while(*dest != '\0') {
		dest++;
	}
	
	for(;*src;) {
		*dest=*src;
		dest++;
		src++;
		}

		return p; 
}

int main()
{

	char str1[20] = "welcome to world";
	char str2[30] = "hai";
	
	my_strcat(str2,str1);
	printf("%s\n",str2);

	return 0;
	
}
