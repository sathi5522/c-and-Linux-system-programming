#include<stdio.h>

int main()
{

	unsigned int i = 0;
	struct a{
	
		int ar[5];
		int re;
	}s= {{1,2,3,4,5},0};

	while(i<5){
			
		s.re = s.re + s.ar[i];
		i++;
		}

	printf("%d\n",s.re);
}
