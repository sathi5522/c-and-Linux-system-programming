#include<stdio.h>
#include<signal.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void sig_han(int signo,siginfo_t *obj,void *p)
{
	printf("the sighandler :%d \n",signo);
}
int main()
{
	int fd;
	char rbuf[5];
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sig_han;
	act.sa_flags = SA_RESTART;	
	if(sigaction(2,&act,NULL) == -1)
		perror("sigaction");
	printf("test\n");
	getchar();
	fd = open("./pone",O_RDWR);
	if(fd < 0)
		perror("open");

	read(fd,rbuf,sizeof(rbuf));
	printf("the read :%s\n",rbuf);
	return 0;
}
