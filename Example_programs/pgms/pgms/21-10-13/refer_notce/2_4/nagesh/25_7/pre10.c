#include <stdio.h>

#define LTOB(data) data = (data >> 24)|(data << 24)| ((data >> 8)& (0x0000ff00))| ((data << 8)&(0x00ff0000))


int main()
{
	unsigned int a = 0x00ffffff;

	LTOB(a);

	printf("%x\n",a);

	return 0;



}
