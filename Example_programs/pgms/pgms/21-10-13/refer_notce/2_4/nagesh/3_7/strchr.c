#include <stdio.h>

char * str_chr( const char *r, int c)
{
	
	
	
	while(*r != c){
		r++;
		
		if(*r == '\0')
			return NULL;		
		}

		

		return (char *)r--;



}





int main()
{

	char s[10] = "naagesiah";
	char *q;

	printf("%p ",s);
	q = str_chr(s,'a');
	
	printf("%p",q);
	return 0;
}
