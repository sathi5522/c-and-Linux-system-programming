#include<stdio.h>
#include<signal.h>
#include<string.h>
void sig_han(int signo,siginfo_t *obj,void *p)
{
        printf("the sighandler :%d \n",signo);
        sleep(5);
        printf("exit sighandler\n");
}
int main()
{
	
        struct sigaction act;
	sigset_t mask;
	
        memset(&act,0,sizeof(act));
        act.sa_sigaction = sig_han;
        
	if(sigaction(SIGALRM,&act,NULL) == -1)
                perror("sigaction");

	
	sigemptyset (&mask);
	sigaddset (&mask, SIGTERM);
 
/*	if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) {
		perror ("sigprocmask");
		return 1;
	}*/

	sigaddset (&mask, SIGINT);

        if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) {
                perror ("sigprocmask");
                return 1;
        }
	alarm(5);
	getchar();
	

//	sigprocmask(SIG_UNBLOCK,&mask,NULL); 
	
        printf("test\n");
        getchar();
	sigprocmask(SIG_UNBLOCK,&mask,NULL);
        for(;;);
                //printf("the test section\n");
        return 0;
}

