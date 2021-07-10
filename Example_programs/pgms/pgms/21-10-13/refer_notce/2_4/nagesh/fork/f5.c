#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int glob = 424;
	pid_t pid;
//	printf("parent message %d\n",glob);
	
	pid = fork();
	
	if(pid == 0)
	printf("child message : %d\n",glob);
	
	else if(pid < 0){
			perror("fork:");
			exit(1);
	}
	else{

			printf("parent message: %d\n",glob);
	}	
	

	return 0;

}
