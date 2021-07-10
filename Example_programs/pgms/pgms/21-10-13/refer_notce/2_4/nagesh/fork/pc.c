#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

	int fd;
	pid_t pid;
	int i;
	char buf[20];
	fd = open("ss.txt",O_RDONLY,0076);
	pid = fork();

	if(pid == 0){
	
		 read(fd,&buf,sizeof(buf));
		for(i = 0; i < 19;i++)
		{
			printf("%c",buf[i]);
		}

		}
	if(pid < 0){

		perror("fork :");
		exit(1);

		}


	if(pid > 0){


		printf("parent program");

		}


		return 0;
}

