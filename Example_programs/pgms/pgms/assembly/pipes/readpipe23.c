#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd1, fd2;
	char buf1[10], buf2[10];
	fd1 = open("./pipe1", O_RDONLY);
	fd2 = open("./pipe2", O_RDONLY);
	
	if(fd1<0){
		perror("open");
		exit(1);
	}
	if(fd2<0){
		perror("open");
		exit(2);
	}
	
	read(fd1, buf1, sizeof(buf1));
	read(fd2, buf2, sizeof(buf2));

	printf(" %s \n %s\n", buf1, buf2);	
	return 0;
}
