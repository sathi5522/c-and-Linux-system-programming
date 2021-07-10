#include <stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int l;
	l = access(argv[1],X_OK);
	
	printf("%d",l);

	return 0;


	
}

