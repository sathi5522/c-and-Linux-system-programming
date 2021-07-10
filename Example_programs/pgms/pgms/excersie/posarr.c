#include<stdio.h>

int pos(int b,int *p)
{
        int j,val,count = b;
	printf("enter the value");
	scanf("%d", &val);
        
        for(j = (b - 1);j >= 0;j--) {
              
		if(val == p[j]) {

			count = count - 1;
			return count;

                }
        }
        return -1;

}

int main()
{
        int size,a[10],i,c;
        scanf("%d", &size);
        for(i = 0;i <= (size - 1);i++) {
                scanf("%d", &a[i]);
        }
        c = pos(size,a);
        printf("%d\n",c);

	return 0;
}                                                  

