#include<stdio.h>
int fun(int n)
{
	static int x = 2;
	if(n){
		x++;
		return (x)*(x);

	}
	else{
		return x*x;
	}

}	

int main()
{
	printf("\n%d", fun(0));
	printf("\n%d", fun(1));
	printf("\n%d", fun(0));
	printf("\n%d", fun(1));
	
	return 0;
}
