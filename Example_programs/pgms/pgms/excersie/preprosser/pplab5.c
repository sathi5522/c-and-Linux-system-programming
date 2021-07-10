#include<stdio.h>

#define SWAP(a)  ((a << 4)|(a >> 4))
                

int main()
{
	unsigned short int x = 10;
        printf("%x\n",SWAP(x));

        return 0;
}

