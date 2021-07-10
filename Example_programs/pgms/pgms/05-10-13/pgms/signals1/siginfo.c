#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h>
void sig_han(int signo,siginfo_t *obj,void *p)
{
	printf("the sighandler num :%d \n",obj->si_signo);
	printf("the sigcode :%d \n",obj->si_code);
	//printf("the sigtrap num :%d \n",obj->si_trapno);
	printf("the process id :%d \n",obj->si_pid);
	printf("the userid :%d \n",obj->si_uid);
	printf("the status :%d \n",obj->si_status);
	printf("the user time second :%d \n",obj->si_utime);
	printf("the system time second :%d \n",obj->si_stime);
	printf("the signal value :%d \n",obj->si_value);
	printf("the signal :%d \n",obj->si_int);
	printf("the signal :%d \n",obj->si_ptr);
	printf("the Timer overrun count :%d \n",obj->si_overrun);
	printf("the timer id:%d \n",obj->si_timerid);
	printf("the memory location :%d \n",obj->si_addr);
	printf("the band event :%ld\n",obj->si_band);
	printf("the file descriptor :%d \n",obj->si_fd);
	//printf("the significant bit address :%d \n",obj->si_addr_lsb);
	printf("the error value :%d \n",obj->si_errno);
}
int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sig_han;
	act.sa_flags = SA_SIGINFO;	
	sigaction(2,&act,NULL);
	printf("test\n");
	getchar();	
	return 0;
}
