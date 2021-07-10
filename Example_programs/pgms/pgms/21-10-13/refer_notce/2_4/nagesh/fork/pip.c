#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{

	pid_t pid;
	int status;
	int fd;
	char ch[8]= "nagesh";
	char sh[8];

		fd = open("pipe",O_RDWR);
		if(fd < 0){

			perror("open");
			exit(2);
		}
	pid = fork();


	if(pid < 0){

		perror("fork");
		exit(1);
	}

	if(pid == 0){
		printf("child process is starting\n");
		read(fd,sh,sizeof(sh));
		printf("%s\n",sh);
		printf("child process is ending\n");
		return 0;

	}

	if(pid > 0){

		printf("parent process is starting\n");
		sleep(5);
		write(fd,ch,sizeof(ch));
		printf("parent process is ending\n");	

		wait(pid,&status);
	}

	
	return 0;


}
