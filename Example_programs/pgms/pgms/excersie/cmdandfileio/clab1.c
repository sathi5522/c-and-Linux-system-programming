#include<stdio.h>

int main(int argc,char *argv[])
{

	int sum = 0;
	printf("count: %d\n",argc);
	for(--argc;argc >= 0;argc--) {
			sum = sum +atoi( argv[argc]);
	}
	printf("the sum of given integers: %d\n",sum);

	return 0;
}
