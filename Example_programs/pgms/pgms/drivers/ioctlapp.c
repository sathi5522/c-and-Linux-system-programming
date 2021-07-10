#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include"ioctl.h"
int main()
{

	int fd,ret;
	unsigned long *arg,size;
	char buf[4096];
	fd = open("/dev/sat4",O_RDWR);
	if(fd < 0)
	{
		return -1;
	}
	/*ioctl(fd,FILL_CHAR,'A');
	read(fd,buf,100);
	printf("%s\n",buf);*/
	ioctl(fd,GET_SIZE,&arg);
	printf("size:%ld\n",arg);
	size = 5096;
	ret = ioctl(fd,SET_SIZE,size);
	printf("%d\n",ret);
	if(ret<0)
		printf("error in set size\n");
	ret = ioctl(fd,GET_SIZE,&arg);
	printf("size:%ld\n",arg);
	return 0;
}
