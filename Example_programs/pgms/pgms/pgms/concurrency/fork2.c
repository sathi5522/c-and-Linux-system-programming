#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t pid;

	int local = 10;

	pid = fork();

	switch(pid){
		case 1: perror("fork");
			exit(1);
			break;

		case 0: printf("In child :%u\n",getpid());
			printf("\t local :%d\n",local);
			break;

		default:printf("In parent :%u\n",getpid());
			printf("\t local :%d\n",local);
			break;

	}
	
	return 0;
}
	
