#include<stdio.h>

void *copy(int *dest,int *src,int size)
{
	int j;
	for(j = 0;j <= (size - 1);j++) {
		*dest = *src;
		src++;
		dest++;
		
	}
	dest -= size;
	return dest;
	
			

}

int main()
{
	int size,a[5] = {1,2,3,4,5},b[5],i;
	int *p;
	
	p = copy(b,a,5);
	for(i = 0;i  < 5;i++)  {
		printf("%d\n",p[i]);
		
	}

		
	return 0;


}
