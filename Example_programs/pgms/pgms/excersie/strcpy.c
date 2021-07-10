
#include<stdio.h>

char *my_strcpy(char *dest,const char *src)
{
	char *s = dest;
	int i = 0;
	for(; *src != '\0';i++) {
		*dest = *src;
		dest++;
		src++;
	}
	
	return s; 
}

int main()
{

	char str1[17] = "welcome to world";
	char str2[17];
	
	my_strcpy(str2,str1);
	printf("%s\n",str2);

	return 0;
	
}
