# include <stdio.h>

unsigned short mid(unsigned long n,unsigned short *p)
{
	unsigned long middle;
	
	middle =  (n-1) / 2;

	return p[middle];
	

}

int main()
{
	unsigned long size = 6, i;

	unsigned short a[size],middle;

	printf("enter array values :\n");
	for(i = 0; i < size; i++)
		scanf("%hd",&a[i]);

	middle = mid(size,a);

	printf("middle value : %hd",middle);
	
	return 0;

}
