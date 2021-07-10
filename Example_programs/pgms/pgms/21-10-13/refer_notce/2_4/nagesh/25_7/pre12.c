#include <stdio.h>

#define MAC(data,f)       (data f;

#define IS_REG     >>0)&1
#define IS_CHAR    >>1)&1
#define IS_BLOCK   >>2)&1
#define IS_LINK    >>3)&1
#define IS_DIR     >>4)&1
#define IS_FIFO    >>5)&1
#define IS_SOCKET  >>6)&1




int main()
{
	
	
	unsigned short int ret, x = 10; 
	
	ret = MAC(11,IS_DIR);

	if(ret  == 0)
		printf("not set");
	else{
		printf("set");
		}

	return 0;

}

