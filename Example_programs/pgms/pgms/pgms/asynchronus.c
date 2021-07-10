#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<signal.h>
#define CHILD 0
int childstatus;
void cleanup(int signum)
{
printf("cleanup \n");
}
int main()
{
	int exit_stat;
	/*int EXIT_SUCESS;*/
	pid_t cpid;
	struct sigaction act;
	cpid=fork();
	if(cpid==CHILD){
		int n=0;
		printf("iam in child task \n");
		while(n<5){
			n++;
		sleep(1);
		printf("child \n");
	}
//	exit(1);
}
	else {
		act.sa_flags=SA_NOCLDSTOP;
		act.sa_handler=cleanup;
	if(sigaction(SIGCHLD,&act,NULL)==-1);
	perror("sigaction");
	while(1){sleep(1);
	printf("child exit status =%d \n",WEXITSTATUS(exit_stat));}
	}
	exit("EXIT_SUCESS");
}
		


