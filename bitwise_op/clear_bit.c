#include<stdio.h>

#define ClearBitInt(A,k)     ( A[(k/32)] &= ~(1 << (k%32)) )
#define ClearBitChar(A,k)    ( A[(k/8)] &= ~(1 << (k%8)) )
int main()
{
	int a[4] = {1,2,3,4};
	int i;
	ClearBitInt(a,98);
	for(i = 0; i<4;i++) {
		printf("%d\n",a[i]);
	}

	char b[3] = {'1','2','3'};
	ClearBitChar(b,0);
	for(i = 0;i < 3; i++) {
		printf("%c %d\n",b[i],b[i]);
	}
	
	return 0;
}
