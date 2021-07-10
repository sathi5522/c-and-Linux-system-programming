#define _GNU_SOURCE
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() 
{
	char *buff;
	int fdin,ret,ret1;
	char *wbuff = "fdgghdfrtuhvvgdsjfjufdjdssjgfkjhgmvgfkvhdfkjf";
	int size = 4096;
	fdin = open("abc.txt",O_DIRECT|O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fdin<0) {
		perror("open error");
		exit(1);
	}

	ret = write(fdin,wbuff,strlen(wbuff));
	if(!ret) {
		perror("write error");
		exit(2);
	}
	ret1 = read(fdin,&buff,sizeof(buff));
	if(!ret1) {
		perror("read error");
		exit(4);
	}
	posix_fadvise(fdin,0,20,POSIX_FADV_SEQUENTIAL);
	printf("%s\n",buff);
	close(fdin);

	return 0;
}
	
	
