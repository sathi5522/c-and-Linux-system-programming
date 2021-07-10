#include<stdio.h>

#define STORE(a,b) {\
			unsigned int x;\
			unsigned short int s,t;\
			x = (a << 16)|b;\
			printf("%x\n",x);\
			}

int main()
{
	unsigned short int z = 0xffdd,y = 0xeedd;
	STORE(z,y)

	return 0;
}
