#include <stdio.h>
#include "ioctl_header.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{

	int fd,ret;
	unsigned int data;


	fd = open("/dev/rtc_driver",O_RDWR);
	if(fd < 0){
		
		perror("open failed\n");
		return 0;
	}
		
	ret = ioctl(fd,READ_YEAR,&data);

	if(ret < 0){

		perror("ioctl:\n");
		return 0;
	}

	printf("data : %x\n",data);

	close(fd);
	return 0;
	



}

