#include<stdio.h>

#define STORE(a,b) {\
			unsigned int x;\
			unsigned short int s,t;\
			x = (a << 16)|b;\
			s = (x >> 16);\
			t = x & 0xFFFF;\
			printf("%x\n",s);\
			printf("%x\n",t);\
			}

int main()
{
	unsigned short int z = 0xffdd,y = 0xeedd;
	STORE(z,y)

	return 0;
}
