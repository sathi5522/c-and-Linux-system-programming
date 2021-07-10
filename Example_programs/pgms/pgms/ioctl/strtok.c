#include <string.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	char *str;
	char *token;
   	int a[3],i;
	str = argv[1];
   	/* get the first token */
   	token = strtok(str,"/");
   
   	/* walk through other tokens */
   	while( token != NULL ) 
   	{
	for(i = 0;i<3;i++) {
		a[i] = atoi(token);
		printf("array:%d\n",a[i]);
	      	printf( " %s\n", token );
	 
      		token = strtok(NULL,"/");
	}
   	}
   
   	return 0;
}
