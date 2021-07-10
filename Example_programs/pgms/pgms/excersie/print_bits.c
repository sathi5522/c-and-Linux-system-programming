#include<stdio.h>

unsigned int  print_bits(unsigned int e,char b )
{
	int i,x;
	b = b * 8;
	//scanf("%d",&i);
	for(i = b-1 ;i >= 0;i--) {
		x = (e >> i) & 1;
		printf("%d",x);
	}
	printf("\n");

	
}

/*int main()
{
	unsigned int a =0xffdeffee;
	
	 print_bits(a,sizeof(a));

	return 0;	
}*/
