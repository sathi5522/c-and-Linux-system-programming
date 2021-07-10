#include<stdio.h>
#include<signal.h>
//typedef void (*sig_han)(int);
void sig_han(int signo)
{
	printf("signal handler:%d\n",signo);
}
int main()
{
	signal(2,sig_han);
	while(1)
		printf("test\n");
	getchar();
	signal(2,SIG_DFL);
	getchar();
//	while(1);
	return 0;
}
