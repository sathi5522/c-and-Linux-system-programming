#include <stdio.h>
#include <signal.h>
#include <string.h>
void handler(int x)
{

	printf("%d signal is exected\n",x);
	
	getchar();
}

int main()
{

	struct sigaction prc;
	sigset_t sigmask;
	sigemptyset(&sigmask);
	sigaddset(&sigmask,SIGQUIT);
	sigaddset(&sigmask,SIGINT);
	memset(&prc, 0, sizeof(prc));
	prc.sa_handler = handler;
	prc.sa_mask = sigmask;

	sigaction(SIGALRM,&prc,NULL);
//	alarm(5);
	while(1){

	}
//	getchar();

	return 0;
	
	
	

}
