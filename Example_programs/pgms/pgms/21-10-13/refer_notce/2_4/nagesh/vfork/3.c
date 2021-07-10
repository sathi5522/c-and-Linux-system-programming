#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int a;
int main()
{
	pid_t pid;
//	int a = 10;
	
	pid = vfork();		


	if(pid == 0)
	{	
		//printf("child process stats\n");
		a = 20;
		printf("child process %d\n",a);
		
	}

	else if(pid < 0)
	{
		perror("vfork :");
		exit(1);
	}
	else
	{
//		a = 30;
		printf("parent process %d\n",a);
	//	printf("parent process ends\n");
		sleep(20);
	}

	return 0;


}

