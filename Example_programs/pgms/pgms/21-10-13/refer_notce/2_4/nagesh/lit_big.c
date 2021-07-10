#include <stdio.h>

unsigned int conv(unsigned int a)
{

	a = (a << 24)|(a >> 24)|((a<<8)&(0x00ff0000))|((a>>8)&(0x0000ff00));

	return a;
}
int main()
{
	unsigned int b = 23,c;
	bin(23);
	c = conv(23);
	bin(c);
	return 0;

}
