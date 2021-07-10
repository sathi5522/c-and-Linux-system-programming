
#define _GNU_SOURCE 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{

	void *buff;
	int fd,a;
	int size = 4096;
	int rcw,rcr;
	

	fd = open("read.txt", O_DIRECT | O_RDWR | O_TRUNC , 0664);

	a = posix_memalign(&buff,size, size*8);

	rcr=read(0, buff,size);
	rcw = write (fd, buff, size);

	
	return 0;
}
