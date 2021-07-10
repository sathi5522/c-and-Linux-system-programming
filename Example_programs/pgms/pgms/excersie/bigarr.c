#include<stdio.h>

int big(int b,int *p)
{
        int j,sum = 0,d;
	d = p[0];
        for(j = 1;j <= (b - 1);j++) {
               if(p[j] > d) {
			d = p[j];
		}
        }
	return d;
       
}

int main()
{
        int size,a[10],i,c;
        scanf("%d", &size);
        for(i = 0;i <= (size - 1);i++) {
                scanf("%d", &a[i]);
        }
        c = big(size,a);
        printf("%d\n",c);

        return 0;
}

