#include<stdio.h>
void posbit(unsigned char a, unsigned char b, char pos,char nbits)
{
	unsigned char  x, y = 1, i;
	x = b >> pos;
	for(i = 1; i <= nbits-1; i++){
		y = y << 1;
		y = y | 1;
	}
	x = x & y;
	x = x << pos;
	y = y << pos;
	y = ~y;
	a = a & y;
	a = a | x;
	print_bits(a,sizeof(a));
	
}

int main()
{
	unsigned char a = 10, b = 25;
	char pos = 2, nbits = 3;
	posbit(a, b, pos, nbits);
	
	return 0;
}
	
	
	
	
	
	
	

