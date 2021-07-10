#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int fd;
	char ubuf;
	char  ubuf1;
	printf("enter the value\n");
	sacnf("%d",&ubuf);

	fd = open("/dev/sat3",O_RDWR);
	write(fd,ubuf,strlen(ubuf));
	read(fd,ubuf1,sizeof(ubuf1));
	printf("%x\n",ubuf1);
	return 0;
}

