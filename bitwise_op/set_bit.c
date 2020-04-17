#include<stdio.h>

#define SetBitInt(A,k)     ( A[(k/32)] |= (1 << (k%32)) )
#define SetBitChar(A,k)    ( A[(k/8)] |= (1 << (k%8)) )
//#define ClearBit(A,k)   ( A[(k/32)] &= ~(1 << (k%32)) )
//#define TestBit(A,k)    ( A[(k/32)] & (1 << (k%32)) 
int main()
{
	int a[4] = {1,2,3,4};
	int i;
	SetBitInt(a,70);
	for(i = 0; i<4;i++) {
		printf("%d\n",a[i]);
	}

	char b[3] = {'1','2','3'};
	//char *p;
	SetBitChar(b,3);
	for(i = 0;i < 3; i++) {
		//p = (char *)&b[i];
		printf("%c %d\n",b[i],b[i]);
	}
	
	return 0;
}
