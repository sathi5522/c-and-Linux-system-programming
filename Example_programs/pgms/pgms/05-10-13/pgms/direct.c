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
	void *buff;
	int fdin,ret,ret1;
	void *wbuff = "fdgghdfrtuhvvgdsjfjufdjdssjgfkjhgmvgfkvhdfkjf";
	int size = 4096;
	fdin = open("abc.txt",O_DIRECT|O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fdin<0) {
		perror("open error");
		exit(1);
	}

	ret = write(fdin,wbuff,sizeof(wbuff));
	if(!ret) {
		perror("write error");
		exit(2);
	}
	posix_memalign(&buff,size,size*8); 
	ret1 = read(fdin,buff,sizeof(buff));
	if(!ret1) {
		perror("read error");
		exit(4);
	}
	printf("%s\n",buff);
	close(fdin);

	return 0;
}
	
	
