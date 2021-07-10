#include <stdio.h>

#define IS_CAP_ALPHA(ch)  (ch >= 'A') && (ch <= 'Z')

int main()
{

	int ret;

	ret = IS_CAP_ALPHA('N');

	printf("%d",ret);

	return 0;
	
}
