#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()

{

	pid_t pid;
	int status;
	pid = fork();

	if(pid == 0)
	{
		printf("chile process starts\n");
		printf("child proces terminate");
//		exit(5);
	}
	
	else if(pid < 0)
	{
		perror("fork :");
		exit(1);
	}


	else
	{

		printf("parent starts\n");
		sleep(10);
		wait(&status);
		printf("%d",WEXITSTATUS(status));
		sleep(10);
		
	}
		

		return 0;

}
