
#include<stdio.h>

char *my_strrchr(const char *src, char c)
{
/*	char *s = src;
	int i;
	for(i = 17;i > 0;i--) {
//		s = s + 1;
		if(c == s[i]) {
			return (s+i);
		}
	}  
 */
	while(*src != '\0') {
		src++;
	}
        do {
                if (*src == c) {
                        return  src;     /* silence the warning */
                }
        } while (src--);

        return NULL;
}

int main()
{

	char str1[17] = "welcome to world";
	int *b;
	b = my_strrchr(str1,'d');
	printf("%u\n",b);
	printf("%c\n",*b);

	return 0;
	
}
