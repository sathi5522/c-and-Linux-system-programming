#include <stdio.h>

char *  str_cat(char *p, const char *r,unsigned int j)
{
	char *t = p;
	unsigned int k = 0;

	while( *t != '\0' )
		t++;
	for(;k < j; k ++)	
	*t++ = *r++;

	return p;
}











int main()
{
	char a[20] = "nagesh";
	char b[5]  = "gunna";
	char *q;
	unsigned int i;

	q = str_cat(a,b,4);
	
	for(i = 0; i < 20; i++)
	printf("%c",a[i]);
	
	return 0; 
	


}
