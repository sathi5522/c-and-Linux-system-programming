#include<stdio.h>

int main()
{
	struct msg {
		char str[20];
		int len;
	};
	struct msg x[2] = {{"hello"},{"hai"}};
	/*x[0].str[0] = 'h';
	x[0].str[1] = 'e';
	x[0].str[2] = 'l';
	x[0].str[3] = 'l';
	x[0].str[4] = 'o';
	x[0].str[5] = '\0';
	x[1].str[0] = 'h';
	x[1].str[1] = 'a';
	x[1].str[2] = 'i';
	x[1].str[3] = '\0';
	*/
	struct msg y;
	strcpy(y.str,x[1].str);
	y.len = strlen(x[1].str);
	//y.len = x[1].len;
	printf("%s %d \n",y.str,y.len);

	return 0;
}
