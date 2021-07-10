#include <stdio.h>

int main()
{
	int n, i,sum=0;
	
	printf("enter any number\n");
	scanf("%d",&n);

	for(i=1; i<=n; i++) 
		
		sum=sum+i;
	
	printf("sum of digits in %d is %d\n",n,sum);
	
	return 0;
	
}
