#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int fd,ret;
	char *writebuff = "hello world";
	char readbuff[20];
	
	if(argc == 1) {
		printf("error");
		exit(1);
	}

	fd = open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd<0) {
		perror("open");
		exit(2);
	}
	printf("the new file descriptor %d\n",fd);
	ret = write(fd,writebuff,strlen(writebuff));
	if(!ret) {
		perror("write");
		exit(3);
	}
	printf("%d bytes written to the file %s\n",ret,argv[1]);
	lseek(fd,0,SEEK_SET);
	ret = read(fd,readbuff,sizeof(readbuff));
	readbuff[ret] = '\0';
	printf("%s\n",readbuff);
	close(fd);

	return 0;
}
