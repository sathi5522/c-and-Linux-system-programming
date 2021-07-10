#include<stdio.h>


unsigned char swap(unsigned char a,unsigned char b,int pos,int nob)
{
	unsigned char x,y = 1,i;
	x = b >> (pos - 1);
	for(i = 1;i <= nob - 1;i++) {
		y = y << 1;
		y = y | 1;
	}
	x = x & y;
	x = x << (pos - 1);
	y = y << (pos - 1);
	y = ~y;
	a = a & y;
	a = a | x;
	print_bits(a,sizeof(a));
	unsigned char z,g = 1,j;
	x = a >> (pos - 1);
	for(j = 1;j <= nob - 1;j++) {
		g = g << 1;
		g = g | 1;
	}
	z = z & y;
	z = z << (pos - 1);
	g = g << (pos - 1);
	g = ~g;
	b = b & g;
	b = b | z;
	print_bits(b,sizeof(b));

 
}

int main()
{
	unsigned char p,q;
	int r,s;
	swap(0xf5,0xad,2,2);
	
	return 0;
}
