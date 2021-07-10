#include <stdio.h>

char *  str_rchr( const char *r, int c)
{
	
	char *t = r;
	while(*t++ != '\0');
	while(*t != c){
	        	
		if(*t--  == *r)
		return NULL;		
	}

		
	return  t;
}





int main()
{

	char s[10] = "naagesiah";
	char *q,*p;

	printf("%x ",&s[7]);
	p =  str_rchr(s,'t');
	
	printf("%p",p);
	return 0;
}
