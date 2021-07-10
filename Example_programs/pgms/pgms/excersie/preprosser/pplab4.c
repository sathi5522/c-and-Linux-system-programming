#include<stdio.h>

#define POSBIT(a,pos) {\
                        int y = 1;\
                        y = y << (pos - 1);\
			y = ~y;\
                        a = a & y;\
                        printf("%d\n",a);\
                      }

int main()
{
        int x = 10, z = 4;
        POSBIT(x,z)

        return 0;
}

