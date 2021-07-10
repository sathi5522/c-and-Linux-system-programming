#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<time.h>

void sig_hand(int signum)
{

	printf("it is in sig_hand function\n");
}

void timesnap(void)
{

	time_t t;

	time(&t);

	printf("time when signal invoked is %s\n", ctime(&t));

}

int main()
{
	int a;
	siginfo_t info;
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGALRM );
	sigaddset(&set, SIGINT);

	timesnap();

	alarm(5);
	sigprocmask(SIG_BLOCK, &set, NULL);

	a = sigwaitinfo(&set, &info);

	printf("%d signal is reached\n", a);

	timesnap();

	return 0;
}

