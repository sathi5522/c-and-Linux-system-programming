#include <stdio.h>
#include <string.h>
int main()
{

	char a[40] = " nagesh hello nagesh hello";
	char b[20] = "hello",*p;


	p = strstr(a,b);
	
	printf("%c",*p);
	return 0;	

}
