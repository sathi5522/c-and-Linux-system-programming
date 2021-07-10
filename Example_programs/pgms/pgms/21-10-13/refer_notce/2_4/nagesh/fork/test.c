#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

	int a = 10;
	pid_t pid;

	pid = fork();

	if(pid == 0){
		a = 20;

		printf("a value %d\n",a);
		
		}

	else if(pid < 0){

		perror("fork : ");
		exit(1);

		}


		else{

			sleep(10);

			printf("a value %d\n",a);
			}


		return 0;

}
