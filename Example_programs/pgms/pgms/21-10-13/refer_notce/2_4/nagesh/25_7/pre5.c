#include <stdio.h>
#define SWAPN(data) ((data>>4)&0x0f)|((data << 4)&0xf0)
int main()
{

	char c = 'A', ret;

	ret = SWAPN(c);
	
	printf("%d\n",ret);

	return 0;

	


}
