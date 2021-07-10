#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define CHILD 0
int children;

void cleanup(int signo)
{
	printf("cleanup child resource\n");
	wait(&children);
}
int main()
{
	struct sigaction act;

	pid_t cpid;	

	cpid = fork();

	if(cpid == CHILD){
		printf("Iam in child task\n");
		return 1;
	}
	else{
		
		act.sa_flags = SA_NOCLDSTOP;
		act.sa_handler = cleanup;
		if(sigaction(SIGCHLD,&act,NULL) == -1);
		perror("sigaction");
		while(1);
	}
	exit(EXIT_SUCCESS);
}


