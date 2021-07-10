#include<stdio.h>
#include<string.h>


int main()
{
	char name[20] = "sathgfdgfi";
	char *c;
	c = strtok(name,"a");
	printf("%s\n",c);

	c = strtok(NULL,"h");
	printf("%s\n",c);
	c = strtok(NULL,"i");
	printf("%s\n",c);

	return 0;
}

	
		
