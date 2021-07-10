#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	char buf[20];
	fd = open("./pipe1", O_RDONLY);
	if(fd < 0){
		perror("open");
		exit(1);
	}
	
	read(fd, buf, sizeof(buf));
	printf("%s", buf);
	return 0;
	
}
