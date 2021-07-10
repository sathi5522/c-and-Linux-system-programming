#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int g = 100;
int main()
{
	pid_t pid;

	pid = fork();

	switch(pid){
		case 1: perror("fork");
			exit(1);
			break;

		case 0: printf("In child :%u\n",getpid());
			printf("\t g :%d\n",g);
			break;

		default:printf("In parent :%u\n",getpid());
			printf("\t g :%d\n",g);
			break;

	}
	
	return 0;
}
	
