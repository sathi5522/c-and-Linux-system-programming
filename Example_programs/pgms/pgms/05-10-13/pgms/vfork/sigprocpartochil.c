#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
void sig_han(int signo)
{
	printf("the signal handler %d\n",signo);
	sleep(5);
	printf("exit signal handler\n");
}
int main()
{
	struct sigaction act;
	sigset_t mask;
	memset(&act,0,sizeof(act));
	act.sa_handler = sig_han;
	if(sigaction(SIGINT,&act,NULL)==-1) 
		perror("sigaction");
	sigemptyset(&mask);
	sigaddset(&mask,3);
	sigaddset(&mask,4);
	if(sigprocmask(SIG_BLOCK,&mask,NULL) < 0){
		perror("sigprocmask");
		return 1;
	}
	pid_t pid;
	pid = vfork();
	if(pid ==0) {
		printf("iam in child task\n");
		getchar();
		exit(1);
	}
	else {
		printf("iam in parent task\n");
	}

	return 0;
}
