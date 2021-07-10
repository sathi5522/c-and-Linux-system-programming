#include<stdio.h>
#include<signal.h>
void sig_han(int signo)
{
	printf("signal handler:%d\n",signo);
}
int main()
{
	signal(10,sig_han);
	printf("test\n");
	getchar();
	signal(10,SIG_DFL);
	getchar();
	return 0;
}
