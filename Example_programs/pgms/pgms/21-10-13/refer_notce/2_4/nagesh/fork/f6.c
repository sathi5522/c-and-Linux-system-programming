#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void handler(int x, siginfo_t *act,void *p)
{
	int status;

	printf("ur entered into handler\n");
//	sleep(5);
		wait(&status);



}




int main()
{
	int glob = 424;
	pid_t pid;
	
	struct sigaction prc;
	memset(&prc,0,sizeof(prc));
	prc.sa_sigaction = &handler;

//	prc.sa_flags = SA_NOCLDSTOP;
//	printf("parent message %d\n",glob);
	
	pid = fork();
	
	if(pid == 0){

	printf("child message : %d\n",glob);
	sleep(15);
	printf("Exiting child process");
//	return 0;
	}	


	else if(pid < 0){
			perror("fork:");
			exit(1);
	}
	else{		
			printf("hello\n");
			sigaction(SIGCHLD,&prc,NULL);
		while(1){
		printf("hello\n");
		sleep(1);
		};
//			printf("hello\n");
//			
			
	}	
	

	return 0;

}
