#include<stdio.h>

int mid(int b,int *p,int g)
{
        int mid,d;
	mid = g / 2;
	d = p[mid];
        
        return d;

}

int main()
{
        int size,a[10],i,c,count = 0;
        scanf("%d", &size);
        for(i = 0;i <= (size - 1);i++) {
                scanf("%d", &a[i]);
		count++;
        }
        c = mid(size,a,count);
	printf("%d\n",c);

	return 0;
}
                                                             
