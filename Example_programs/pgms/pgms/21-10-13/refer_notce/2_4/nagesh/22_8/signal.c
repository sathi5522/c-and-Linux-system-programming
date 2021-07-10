#include <stdio.h>
#include <signal.h>
#include <string.h>



void sig_hand(int x)
{
	printf("application defined handler no :%d , pid : %u\n",x,getpid());
	getchar();
}


int main()
{

	 struct sigaction prc1;

	memset(&prc1,0,sizeof(prc1));
	prc1.sa_handler = sig_hand;
	prc1.sa_flags = SA_RESETHAND;


	sigaction(2,&prc1,NULL);
	getchar();
	while(1){
	printf("hello\n");
	}
		
	return 0;
}

