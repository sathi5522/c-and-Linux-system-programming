#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	
	fd = open("./pipe1", O_WRONLY);
	if(fd < 0){
		perror("open");
		exit(1);
	}
	
	write(fd, "hello veda", 12);
	return 0;
	
}
