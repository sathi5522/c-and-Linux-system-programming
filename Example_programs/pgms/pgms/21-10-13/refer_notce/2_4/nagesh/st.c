# include <stdio.h>

unsigned short int charst(unsigned char a,unsigned char b)
{

	unsigned short int c = 0x0000;

	c = a;
        c = c << 8;
	c = c | b;
	return c; 

}

int main()
{
	unsigned char l ='A', m = 'B';
	unsigned short int n;
	n = charst(l,m);

	printf("%hu",n);
	return 0;
	
}
