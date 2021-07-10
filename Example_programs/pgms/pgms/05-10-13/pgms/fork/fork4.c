/* parent process terminates child process run*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;

	pid = fork();
	switch(pid) {
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("child message %d\n",getpid());
			getchar();
			break;
		default:
		
			printf("parent message %d\n",getpid());
			sleep(10);
			break;
	}
	return 0;
}
