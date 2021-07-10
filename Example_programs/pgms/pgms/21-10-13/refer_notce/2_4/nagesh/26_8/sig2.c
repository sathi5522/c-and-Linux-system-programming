#include <stdio.h>
#include <signal.h>
#include <string.h>
void handler(int x)
{
	printf("signal exexuted");
	getchar();
}

void check_block()
{
	int res;
	sigset_t op;
	sigprocmask(SIG_BLOCK|SIG_SETMASK,NULL,&op);
	res = sigismember(&op,SIGQUIT);
	
	if(!res)
	printf("unblocked\n");
	else{
	printf("block\n");
	}



}

int main()
{

	struct sigaction prc;
	sigset_t set,set2;
	sigemptyset(&set);
	sigaddset(&set,SIGQUIT);
	//sigaddset(&set,SIGINT);
	memset(&prc,0,sizeof(prc));
	prc.sa_handler = handler;

	check_block();

	sigprocmask(SIG_BLOCK,&set,NULL);


	check_block();



	sigprocmask(SIG_UNBLOCK,&set2,NULL);
	
	check_block();		
	return 0;
	




}

