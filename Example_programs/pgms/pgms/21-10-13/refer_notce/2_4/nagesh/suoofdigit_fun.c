#include <stdio.h>

int sumofdigi(int no)
{
	int sum = 0, rem;

	while( no!= 0){

		rem = no % 10;
		sum = sum + rem;
		no = no / 10;
	}

	return sum;
}

int main()
{
	int num;

	printf("enter any number");
	scanf("%d",&num);
	printf("sum of digits in a given number is %d",sumofdigi(num));

	return 0;
}
