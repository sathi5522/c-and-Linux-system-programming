#include<stdio.h>
       #include <sys/types.h>
       #include <sys/stat.h>

#include<string.h>

#include<fcntl.h>
int main()
{
	int fd;
	char ubuf[10] = "Hello";
	char ubuf1[20];
	fd = open("/dev/sat",O_RDWR);
//	write(fd,ubuf,strlen(ubuf));
	read(fd,ubuf1,sizeof(ubuf1));
	printf("%s\n",ubuf1);
	return 0;
}

