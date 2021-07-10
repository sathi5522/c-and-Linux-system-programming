#include <stdio.h>

int main()
{

	int a, b, c;

	printf("enter any two numbers");

	scanf("%d%d",&a,&b);

//	c = a > b ? a : b ;
//	printf("biggest number is : %d\n",c);
	if(a>b)
		
		printf("biggest number is :  %d\n",a);

	else {

		printf("biggest number is :  %d\n",b);
        }

	return 0;

}
	


