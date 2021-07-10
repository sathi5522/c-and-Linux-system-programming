#include<stdio.h>

#define EVEN(a) ((a % 2) == 0 )?1:0

int main()
{
        int x = 11;
        printf("%d\n",EVEN(x));

        return 0;
}

