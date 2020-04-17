#include<stdio.h>

#define ToggleBitInt(A,k)     ( A[(k/32)] ^= (1 << (k%32)) )
#define ToggleBitChar(A,k)    ( A[(k/8)] ^= (1 << (k%8)) )
int main()
{
	int a[4] = {1,2,3,4};
	int i;
	ToggleBitInt(a,99);
	for(i = 0; i<4;i++) {
		printf("%d\n",a[i]);
	}

	char b[3] = {'1','2','3'};
	ToggleBitChar(b,1);
	for(i = 0;i < 3; i++) {
		printf("%c %d\n",b[i],b[i]);
	}

	int c = 256;
	int x = 1;
	x = x << 7;
	c = c^x;
	printf("%d \n",c);	
	return 0;
}
