#include<stdio.h>

int nextsqr(int a)
{
	static int x = 5;
	int nextval;
	

	if(a > 0) {
		nextval = ++x;
		return (nextval) * (nextval);
	}
	else {
		return x * x;
	}
	//nextval++; 
}

int main()
{
	int r,a;
	while(1){
	printf("Enter '1' or '0' : ");
	scanf("%d",&a);
	r = nextsqr(a);
	printf("%d \n",r);
	}
	
	return 0;

}
