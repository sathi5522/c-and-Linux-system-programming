#include <stdio.h>

void rev(unsigned long n, unsigned short *p)
{

	unsigned long i,j; 
	unsigned short b[n];

	for(i = (n-1),j = 0; i < n; i--,j++)
		
		b[j] = p[i];

	for(i = 0; i < n; i++)
		printf("%hd\n",b[i]);


}

int main()
{

	unsigned long size = 5,i;
	unsigned short a[5];

	printf("enter array values: \n");

	for(i = 0;i < size;i++)
	scanf("%hd",&a[i]);

	rev(size,a);

	return 0;
}
