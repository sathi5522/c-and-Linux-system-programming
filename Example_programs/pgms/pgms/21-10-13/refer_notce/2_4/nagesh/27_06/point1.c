# include <stdio.h>

int main()
{
	unsigned int k = 0xff00eeee,l;
	unsigned char *a,*b;

	a = (char*)&k;
	b = (char*)&l;

	*b = *(a + 3);
	*(b + 1)  = *(a + 2 );
	*(b + 2)  = *(a + 1);
	*(b + 3)  = *a;

	printf("%x\n",k);
	printf("%x",l);
	
	return 0;

}
