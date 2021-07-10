#include <stdio.h>

void bin(unsigned long int,short int);
void pos_ret(unsigned int,unsigned int,unsigned short int,unsigned short int);
int main(void)
{

	unsigned 	int a = 0, b;
	unsigned short int pos, nob;

	printf("enter data : \n");
	scanf("%d",&b);

	printf("enter position :\n");
	scanf("%hd",&pos);

	printf("enter no of bits : \n");
	scanf("%hd",&nob);

	bin(b,sizeof b);
	printf("\n");

	pos_ret(a,b,pos,nob);
	return 0;
}
