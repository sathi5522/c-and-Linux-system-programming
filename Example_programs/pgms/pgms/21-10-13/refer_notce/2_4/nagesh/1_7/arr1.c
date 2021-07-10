#include <stdio.h>

unsigned int  sum(unsigned long  n, unsigned short *p)
{

	unsigned int sum = 0,i;
	for(i= 0; i < n; i++)
		sum = sum + p[i];

	return sum;

}

int main()
{

	unsigned long int size = 5,result;
	unsigned short a[size],i;

	printf("enter array values : \n");
	for(i = 0; i < size; i ++)
	scanf("%hd",&a[i]);

	result = sum(size, a);
	
	printf("%ld\n",result);

	return  0;

}
