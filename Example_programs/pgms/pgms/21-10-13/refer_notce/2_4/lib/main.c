#include <stdio.h>
#include "libnag.h"
int main()
{
	int l, f, s, p;

	printf("enter any number\n");
	scanf("%d",&l);


	f = factorial(l);
	s = sumofdigi(l);
	p = palindrome(l);

	printf("factorial of %d is %d\n",l,f);
	printf("sum of digits in %d is %d\n",l,s);
	printf("palindrome %d\n",p);

	return 0;
	
}

