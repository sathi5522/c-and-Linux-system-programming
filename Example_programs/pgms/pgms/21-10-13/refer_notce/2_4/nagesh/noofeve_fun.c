#include <stdio.h>

int noofeve(int x)
{
	int rem,count;

	count = 0;
	 while(x!=0){

                rem = x % 10;
                if(rem % 2 == 0)
                        count++;
                x = x / 10;
	}

	return count--;
}

int main()
{
	int no;
	
	printf("enter any number\n");
	scanf("%d",&no);
	printf("no of evendigits in a %d is %d",no,noofeve(no));

	return 0;


}
