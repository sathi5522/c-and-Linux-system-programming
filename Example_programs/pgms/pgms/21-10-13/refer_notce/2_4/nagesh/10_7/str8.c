#include <stdio.h>

int main()
{
	
	struct msg{

		int a;
		char c;
	}obj[2],nobj;

	
	obj[0].a  = 2;
	obj[0].c = 'c';

	obj[1].a  = 3;
	obj[1].c = 'd';

	nobj.a = obj[1].a;
	nobj.c = obj[1].c;

	printf("%d ",nobj.a);
	printf("%c ",nobj.c);

 	return 0; 
}
