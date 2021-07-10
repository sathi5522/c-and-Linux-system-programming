
#include<stdio.h>

void *my_memcpy(void *dest,const void *src,int n)
{
	int i = 0;
	for(; i < n;i++) {
		*(char *)dest = *(char *)src;
		dest++;
		src++;
	}
	//*(char *)dest = '\0';
	
	return dest - n; 
}

int main()
{

	char str1[17] = "welcome to world";
	char str2[17];
	
	int a[3] ={1,2,3};
	int b[3],i;
	my_memcpy(str2,str1,sizeof(str2));
	printf("%s\n",str2);
	

	my_memcpy(b,a,sizeof(b));
	for(i = 0;i < 3;i++) {

		printf("%d\n",b[i]);
	}

	return 0;
	
}
