#include <stdio.h>

char *  str_cat(char *p, const char *r)
{
	char *t = p;

	while( *t != '\0' )
		t++;
		
	while((*t++ = *r++) != 0);

	return p;
}











int main()
{
	char a[20] = "nagesh";
	char b[5]  = "gunna";
	char *q;
	unsigned int i;

	q = str_cat(a,b);
	
	for(i = 0; i < 20; i++)
	printf("%c",a[i]);
	
	return 0; 
	


}
