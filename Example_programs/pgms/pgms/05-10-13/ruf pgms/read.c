/* when open a file before fork they can read the file in child process and close the file in child process,they can read parent process.how many charcters read in child process after next character they will read parent process*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int fd,ret;

	char buf[20];

	pid_t pid;

	fd = open("./test.file",O_RDWR);
	if(fd < 0){
		perror("open");
		exit(1);
	}
	printf("new file descriptor :%d\n",fd);

	pid = fork();
	
	if(pid == 0){
		ret = read(fd,buf,4);
		if(ret < 0)
			perror("child read:");
		buf[ret] = '\0';
		printf("In child:%s\n",buf);
	
		close(fd);
		ret = read(fd,buf,4);
		if(ret < 0)
			perror("child read:");
	}
	else{
		wait(NULL);
		ret = read(fd,buf,14);
		if(ret < 0)
			perror("parent read:");
		buf[ret] = '\0';
		printf("In parent:%s\n",buf);
	}

	return 0;
}
	

