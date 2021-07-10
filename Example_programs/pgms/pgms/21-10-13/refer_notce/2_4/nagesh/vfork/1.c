#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	
	pid = vfork();
		
	if(pid == 0)
	{	
		printf("child process stats\n");
		sleep(5);
		printf("child process ends\n");
		
	}

	else if(pid < 0)
	{
		perror("vfork :");
		exit(1);
	}
	else
	{
		printf("parent process starts\n");
		printf("parent process ends\n");
	}

	return 0;


}

