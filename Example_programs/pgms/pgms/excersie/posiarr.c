#include<stdio.h>

void pos(int a,int *p)
{
	int j,val,count = 0,c;
	printf("enter the value");
	scanf("%d",&val);
	for(j = 0;j <= (a - 1);j++) {
		count++;
		if(val == p[j]) {
			c = count - 1;
			printf("%d\n",c);
		}
	}
			

}

int main()
{
	int size,a[100],i;
	printf("enter the size");
	scanf("%d",&size);
	for(i = 0;i  <= (size - 1);i++)  {
		scanf("%d",&a[i]);
	}
	pos(size,a);
	
	return 0;


}
