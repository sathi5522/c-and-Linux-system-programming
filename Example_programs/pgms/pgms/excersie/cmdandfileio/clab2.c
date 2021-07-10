#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{

	
	float sum = 0.0;
	int i;
        printf("count: %d\n",argc);
       for(--argc;argc >= 0;argc--) {
                        sum = sum +atof(argv[argc]);
        }
        printf("the sum of given integers: %f\n",sum);

        return 0;

}
