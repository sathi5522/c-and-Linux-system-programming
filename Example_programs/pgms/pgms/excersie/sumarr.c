#include<stdio.h>

int sum(int b,int *p)
{
	int j,sum = 0;
	for(j = 0;j <= (b - 1);j++) {
		sum = sum + p[j];
	}
	return sum; 
}

int main()
{
	int size,a[10],i,c;
	scanf("%d", &size);
	for(i = 0;i <= (size - 1);i++) {
		scanf("%d", &a[i]);
	}
	c = sum(size,a);
	printf("%d\n",c);
	
	return 0;
}
