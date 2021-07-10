#include <stdio.h>

int main()
{
	int n, sum=0, tmp, rem;

	printf("enter any number\n");
	scanf("%d",&n);
	tmp=n;
	
	while(n!=0){
		
		rem = n % 10;
		sum = sum + rem;
		n = n / 10;
	}

	printf("sum of digits in a %d is %d\n",tmp,sum);

	return 0;
}
