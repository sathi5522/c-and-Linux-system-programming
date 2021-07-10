#include <stdio.h>

int main()
{
	int n, count = 0, tmp, rem;

	printf("enter any number\n");
	scanf("%d",&n);
	tmp = n;

	while(n!=0){
		
		rem = n % 10;
		if(rem % 2 == 0)
		
			count++;
		n = n / 10;
	}

	printf("no of even digits in a %d is %d\n",tmp,count);

	return 0;
}
