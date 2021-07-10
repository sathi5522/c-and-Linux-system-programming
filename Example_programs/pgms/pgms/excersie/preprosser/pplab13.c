#include<stdio.h>

#define SETDATE(d,m,y,z) {\
			m = m << 5;\
			y = y << 9;\
			z = d | m |y;\
			printf("%d\n",z);\
			}
#define GETDATE(x) {\
			unsigned short int a,b,c;\
			a = 0x1f & x;\
			b = (0x1e0 &x) >> 5;\
			c = (0xfe00 & x) >> 9;\
			printf("%d: %d: %d \n",a,b,c);\
			}

int main()
{

	unsigned short int j = 26,k = 7,l = 13,q;
	SETDATE(j,k,l,q)
	GETDATE(q)

	return 0;
}  
