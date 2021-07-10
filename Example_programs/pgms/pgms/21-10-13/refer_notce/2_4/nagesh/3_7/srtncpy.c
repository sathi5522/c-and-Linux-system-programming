#include <stdio.h>

char *  strncpy(char *q, const char *p, unsigned int n)
{
	unsigned int i = 0;
	char *s = q;

	for(;i<n;i++)
		*s++ = *p++;
		
	return q;

}

int main()
{
	
	unsigned int i,no = 5;
	char m[15] = "string copied";
	char n[17],*j;
	
	
	j = strncpy(n,m,no);

		for(i =0; i < no; i++)
		 printf("%c",n[i]);

	return 0;	
}
