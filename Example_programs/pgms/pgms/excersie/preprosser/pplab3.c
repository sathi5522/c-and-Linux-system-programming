#include<stdio.h>

#define POSBIT(a,pos) {\
			int y = 1;\
			y = y << (pos - 1);\
			a = a | y;\
			printf("%d\n",a);\
		      }

int main()
{
        int x = 10, z = 3;
        POSBIT(x,z)

        return 0;
}

