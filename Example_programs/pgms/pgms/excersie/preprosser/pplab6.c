#include<stdio.h>

#define SWAP(a) a = ((a << 8) | (a >> 8))

int main()
{
       unsigned short int x = 0xddee;
       printf("%x\n",SWAP(x));

        return 0;
}

