#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	int a = 10;
	pid = fork();
	switch(pid) {
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("child message %d\n",getpid());
			printf("child message %d\n",a);
			break;
		default:
		
			printf("parent message %d\n",getpid());
			printf("parent message %d\n",a);
			break;
	}
	return 0;
}
