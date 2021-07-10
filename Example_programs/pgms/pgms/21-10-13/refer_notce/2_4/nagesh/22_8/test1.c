#include <stdio.h>
#include <signal.h>

void sig_hand(int x)
{
	printf("ur signal handler\n");
	getchar();	

}


int main()
{
//	getchar();
//	signal(2,sig_hand);
//	getchar();	

	

	signal(32,sig_hand);	

	while(1)
	printf("l");

	return 0;

}
