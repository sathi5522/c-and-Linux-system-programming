#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
void sig_hand(int x, siginfo_t * obj, void *z)
{
	
	printf("welcome to new signalhandler\n");
//	printf("%d\n",obj->si_status);
	//sleep(15);
//	alarm(5);
	printf("exit\n");
	
}

int main()
{
	
	int fd;
	char buf[10];
	ssize_t k;

	struct sigaction prc;
	prc.sa_sigaction = sig_hand;
	prc.sa_flags = SA_RESTART;
	sigaction(2,&prc,NULL);
///	alarm(5);
//	getchar();	
	
	fd = open("pipe",O_RDWR,00700);
	if(fd < 0){
		perror("open");
		exit(1);
		}

	k = read(fd,&buf,sizeof(buf));

	if(k < 0){
		perror("read:");
		exit(2);
		}

	while(1){

	}


	return 0;

}


