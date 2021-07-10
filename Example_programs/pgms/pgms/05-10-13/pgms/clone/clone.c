#include<stdio.h>
#include<sched.h>
#include<stdlib.h>
//#define _GNU_SOURCE
#define STACK_SIZE 16000
int child(void *arg)
{
//	fflush(stdout);
	printf("iam child process\n");
	getchar();
}

int main()
{
	void *child1;
	child1 = malloc(STACK_SIZE);
	clone(child,child1 + STACK_SIZE,CLONE_VM |CLONE_FILES,NULL);
	printf("iam in parent process\n");
	while(1);
	
	return 0;

}

