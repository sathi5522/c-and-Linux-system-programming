#include<stdio.h>

unsigned int toggle(unsigned int c,unsigned int pos)
{
	unsigned int x = 1;
	x = x << pos - 1;
	for(;;) {
	c = c ^ x;
	print_bits(c);
	}
	//return c;

}

int main()
{
	unsigned int a = 10, b = 4;
	 toggle(a,b);
	//print_bits(y);
	
	return 0;
}
