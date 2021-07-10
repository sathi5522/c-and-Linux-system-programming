#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	int status;
	pid_t pid;
	pid = fork();

	
	if(pid == 0)
	{
		printf("child process\n");
//		sleep(15);
	}

	else if(pid < 0)
	{
		perror("fork : ");
		exit(1);		
	}

	else {

		printf("paren process starts");
		wait(&status);

//		while(1);
		printf("parent process ends");		

//		sleep(10);
		}

		return 0;
}
