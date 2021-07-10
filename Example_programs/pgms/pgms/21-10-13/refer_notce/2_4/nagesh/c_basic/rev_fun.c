#include <stdio.h>

int rev(int x)
{

	int reverse = 0,rem;

	while(x != 0){

		rem = x % 10;
		reverse = (reverse * 10) + rem;
		x = x / 10;
	}
	
	 return reverse;
}

int main()
{

	int i;

	printf("enter any number\n");
	scanf("%d",&i);
	printf("reverse of a given number is %d",rev(i));

	return 0;
	
}
