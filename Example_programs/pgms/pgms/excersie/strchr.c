
#include<stdio.h>

char *my_strchr(const char *src, char c)
{
	char *s = src;
	int i;
	for(i = 0;s[i];i++) {
//		s = s + 1;
		if(c == s[i]) {
			return (s+i);
		}
	}  
 
}

int main()
{

	char str1[17] = "welcome to world";
	int *b;
	b = my_strchr(str1,'l');
	printf("%u\n",b);
	printf("%c\n",*b);

	return 0;
	
}
