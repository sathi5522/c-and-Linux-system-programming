#include <stdio.h>
#include <string.h>
int main()
{

	struct msg{
	
	char str[20];
	int len;
	}obj = {"veda solu tions",20},*p,**q;

	p = &obj;
	q = &p;

	
	(*q)->str[0] = 'z';

	 (*q)->len  = strlen( obj.str);
	printf("%d %s ",  (*q)->len,(char *)*q );
	
	return 0;


}
