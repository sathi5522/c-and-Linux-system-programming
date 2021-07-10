# include <stdio.h>
void bin(unsigned long int,unsigned short);

void swap(unsigned short a, unsigned short b,unsigned short pos, unsigned short  nob)
{

	unsigned short c = 0xffff,tmp1,tmp2;
	
	c = (c >> (16 - ((pos-1) + nob)))&(c << (pos - 1));

	tmp1 = ((~c)&a)|(b&c);
	tmp2 = ((~c)&b)|(a&c);

	a = tmp1;
	bin(a,sizeof a);
	printf("\n");

	b = tmp2;
	bin(b,sizeof b);
	printf("\n");

}

int main()
{
	unsigned short a = 0xffff, b = 0xeeee,pos =3,nob =4;


	swap(a,b,pos,nob);
	return 0;

}

