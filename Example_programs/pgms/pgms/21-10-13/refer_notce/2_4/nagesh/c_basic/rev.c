#include <stdio.h>

int main()
{
	int no,rem,rev,tmp;

	rev = 0;
	printf("enter any number");
	scanf("%d",&no);
	tmp = no;

	while(no != 0){

	rem = no % 10;
	rev = (rev*10) + rem;
	no = no / 10;
	}

	if(tmp == rev)
		printf("%d is a palindrome \n",tmp);

	else{

		printf("%d is not a pallindrome",tmp);
	}

	return 0;	
	
}
