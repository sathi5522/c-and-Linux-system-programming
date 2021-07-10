#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;

	int exit_stat;

	int tri_pid;
	
	pid = fork();

	switch(pid){
		case 1: perror("fork");
			exit(1);

		case 0: printf("In child :%u\n",getpid());
			sleep(10);
			return 1;
			break;

		default:printf("in parent :%u\n",getpid());

			tri_pid = wait(&exit_stat);
				if(tri_pid < 0) 
					perror("wait");
					printf("exit state of child : %d\n",WEXITSTATUS(exit_stat));

			getchar();
			break;
	}

	return 0;
}
