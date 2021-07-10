#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
void handler(int x)
{

	printf("hello sir\n");

}


int main()
{

	pid_t pid;

	pid = fork();
	struct sigaction prc;
	memset(&prc,0,sizeof(prc));
	prc.sa_handler = handler;
	prc.sa_flags = SA_RESTART;

	sigaction(2,&prc,NULL);
	if(pid == 0)
	{
		printf("child process stats\n");
		sleep(20);
		printf("child process ends\n");

	}

	else if(pid < 0)
	{
		perror("fork :");
		exit(1);

	}
	else
	{
//		sigaction(2,&prc,NULL);
		printf("paren process starts\n");
// 		sleep(10);
		printf("end\n");
	}


		return 0;
}
