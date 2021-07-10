#include <stdio.h>
#define SWAPN(data) ((data>>8)&0x00ff)|((data << 8)&0xff00)
int main()
{

	unsigned short int  c = 32768, ret;

	ret = SWAPN(c);
	
	printf("%hu\n",ret);

	return 0;

	


}
