#include<stdio.h>

int *rev(int a,int *p)
{
	int j,d[3]={0};
	for(j = (a - 1);j >= 0;j--) {
		d[a-j-1] = p[j];
		
		
	}
	return d;
			

}

int main()
{
	int size,a[5]={0},i;
	int *e;
	printf("enter the size");
	scanf("%d",&size);
	for(i = 0;i  <= (size - 1);i++)  {
		scanf(" %d",&a[i]);
	}
	e = rev(size,a);
	for(i = 0;i <= (size - 1);i++) {
		printf("%d\n",e[i]);
	}	
	return 0;


}
