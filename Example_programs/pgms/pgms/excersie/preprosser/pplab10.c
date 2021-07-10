#include<stdio.h>

#define SWAP(a) ((a << 24) | (a >> 24)|((a << 8) & 0x00ff0000)|((a >> 8) & 0x0000ff00))

int main()
{
       unsigned int x = 0xff00faff;
       printf("%x\n",SWAP(x));

        return 0;
}

