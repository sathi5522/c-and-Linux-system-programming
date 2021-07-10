#include <stdio.h>

unsigned short big(unsigned long  n, unsigned short *p)
{
	unsigned short  tmp,tmp2 ;
	unsigned long i = 0;

	tmp2 = p[0];

	for(i = 1; i < n; i++){

		tmp2 = (tmp2 > p[i])?tmp2:p[i];
	}

	return tmp2; 

			
}

int main()
{

	unsigned long size = 5,i = 0;
	unsigned short a[size],result;

	printf("enter array values : \n");

	for(i = 0;i< size;i++)
		scanf("%hd",&a[i]);

	result = big(size,a);
	
	printf("biggest number is : %hd\n",result);

	return 0;

}
