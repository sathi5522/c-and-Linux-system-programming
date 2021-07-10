#include <stdio.h>

int main()
{
	int no, count=0, tmp;
		
	printf("enter any number");
	scanf("%d",&no);
	tmp = no;

	while(no != 0)	{

		no /= 10;
		count++;
	}
	printf("no of digits in a %d is : %d ",tmp,count);

	return 0;
	
}

