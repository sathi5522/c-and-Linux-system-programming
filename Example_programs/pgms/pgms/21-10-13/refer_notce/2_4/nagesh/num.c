#include <stdio.h>

int lsb(int a)
{
	int last = 0x01;
	
	return a & last;


}

int son(int a, int pos)
{

	int some = 0x01;
	some = some  <<  (pos-1);
	
	return a|some;

}

int sof(int a, int pos)
{
	int some1, some2, result;
  
	some1 = 0xffff;
	some2 = 0x01;
	
	some2 = some2 << (pos - 1);
	result = some1 ^ some2;

	return result & a;
	 

}



int main()
{
	int a, l, pos, sn, so ;
		
	a = 26;
	pos = 4;

	l = lsb(a);
	printf("%d\n",l);

	sn = son(a, pos);
	printf("%d\n",sn);

	so = sof(a, pos);
	printf("%d\n",so);

	

	return 0;
}
