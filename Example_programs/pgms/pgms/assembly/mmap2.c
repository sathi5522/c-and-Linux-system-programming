#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include <sys/mman.h>

struct msg{
	char msg[100];
	int len;
	};

int main()
{
	
	int fd,i;
	struct msg *filedata = NULL, temp;

	struct msg m[3] = {{"xyz",3},{"bcd",3},{"pqr",3}};

	fd = open("hai.txt",O_RDWR);
	filedata = mmap(NULL,512,PROT_READ|PROT_WRITE,MAP_SHARED, fd,0);
	if(!filedata){
		perror("mmap");
		exit(1);
	}
		close(fd);
	for(i = 0; i <3; i = i+2){

		filedata[i]=m[i];
		}
		msync(filedata,512,MS_ASYNC);
		

	for(i = 0; i <3; i = i+2){

		temp=filedata[i];
	printf("%5s\t%2d\n",temp.msg,temp.len);
		}

	munmap(filedata,512);
	
	return 0;
}
		
	
