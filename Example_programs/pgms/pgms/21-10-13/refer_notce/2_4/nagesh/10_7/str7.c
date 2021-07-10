#include<stdio.h>
int main()
{

	unsigned int i = 0;
	struct msg{

		char str[20];
		int len;
	}obj;

	obj.str[0] = 'n';

	obj.str[1] = 'n';

	obj.str[2] = 'n';

	obj.str[3] = '\0';

	while(obj.str[i] !=  '\0')
		i++;

	obj.len = i;
	printf("%d  ",obj.len);



}
