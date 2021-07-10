#include <stdio.h>
#include <string.h>

int main()
{

	char s[40] = "nagesh nagesh nages nagesh nagesh gunna";

	char k[7] = "nag";
	
	
	
	
	printf("%s\n", strtok(s,k));
	
	printf("%s\n", strtok(NULL,k));
	printf("%s\n", strtok(NULL,k));
	printf("%s\n", strtok(NULL,k));
	printf("%s\n", strtok(NULL,k));
	printf("%s\n", strtok(NULL,k));
	printf("%s\n", strtok(NULL,k));
	return 0;





}
