#include<stdio.h>

unsigned int onbit(unsigned int a,int pos1,int pos2,int pos3)
{
	unsigned int x = 1,b,c,d,e;
	b = x << (pos1 - 1);
	c = x << (pos2 - 1);
	d = x << (pos3 - 1);
	e = b | c | d;
	a = a | e; 
	return a;
}
unsigned int offbit(unsigned int a,int pos1,int pos2,int pos3)
{
	unsigned int x = 1,b,c,d,e;
	b = x << (pos1 - 1);
	c = x << (pos2 - 1);
	d = x << (pos3 - 1);
	e = b | c | d;
	e = ~e;
	a = a & e; 
	return a;
}
unsigned int toggle(unsigned int a,int pos1,int pos2,int pos3)
{	
	unsigned int x = 1,b,c,d,e,i =1;
	b = x << (pos1 - 1);
	c = x << (pos2 - 1);
	d = x << (pos3 - 1);
	e = b | c | d;
	
	for(;i <= 5;i++) {
		a = a ^ e;
		print_bits(a,sizeof(a));
	}
	
	
}


int main()
{
	unsigned int e = 0xfa,c,d;
	int b = 1,g = 3,f = 5;
 	c = onbit(e,b,g,f);
	print_bits(c,sizeof(c));
	d = offbit(e,b,g,f);
	print_bits(d,sizeof(d));
	toggle(e,b,g,f);
	

	return 0; 
}
