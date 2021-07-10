#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd1, fd2;
	fd1 = open("./pipe2", O_WRONLY);
	if(fd1<0){
		perror("open");
		exit(1);
	}

	if(fd1<0){
		perror("open");
		exit(1);
	}

	return 0;
}
