
#include<stdio.h>

char *my_strncpy(char *dest,const char *src,int size)
{
	
	int i = 0;
	for(;i < size;i++) {
		*dest = *src;
		dest++;
		src++;
		
	}
	dest[i + 1] = '\0';
	return dest; 
}

int main()
{

	char str1[17] = "welcome to world";
	char str2[4];
	
	my_strncpy(str2,str1,4);
	printf("%s\n",str2);

	return 0;
	
}
