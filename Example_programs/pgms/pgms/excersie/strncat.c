
#include<stdio.h>

char *my_strncat(char *dest,const char *src,int size)
{
	char *p = dest;
	int i = 0;
	while(*dest != '\0') {
		dest++;
	} 	
	
	for(;i < size;i++) {
		*dest = *src;
		dest++;
		src++;
		
	}
	
	return p; 
}

int main()
{

	char str1[17] = "welcome to world";
	char str2[20] = "hai ";
	
	my_strncat(str2,str1,4);
	printf("%s\n",str2);

	return 0;
	
}
