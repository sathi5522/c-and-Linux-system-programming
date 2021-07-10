 #include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int k;
	k = open(argv[1],O_WRONLY|O_CREAT,00700);
	printf("%d",k);

	return 0;

}


