#include <stdio.h>

void print_bit(unsigned long int a, unsigned  short int b)
{
	b = b*8;
	int i = b-1;
	for(;i >= 0; i--){

		printf("%lu ",(a>>i)&1);
	
	}
	printf("\n");
}
int main()
{

	unsigned long int a = 23;
	short int b = 32;
	char c = 'a';
 	print_bit(a,sizeof a);
	print_bit(b,sizeof b);
	print_bit(c,sizeof c);

	return 0;
}
