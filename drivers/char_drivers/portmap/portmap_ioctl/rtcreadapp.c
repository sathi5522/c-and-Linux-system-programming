#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include<sys/ioctl.h>
#include"ioctl.h"
#include <unistd.h>
int main()
{
	int fd,ret;
	char arg[20];
	char out[20];

	fd = open("/dev/sathi",O_RDWR);
	if(fd < 0)
	{
		perror("open");
	}

	ret = ioctl(fd,READ_ALL,&arg);

	if(ret == -1) {
		perror("ioctl");
	}

	printf("%s\n",arg);

	close(fd);

	return 0;
}
