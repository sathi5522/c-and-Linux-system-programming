#include <stdio.h>

unsigned long  position(unsigned long n, unsigned short *p,unsigned short ele)
{
	unsigned long i;
	unsigned long result1 = 0,result2;

	for(i = 0; i <n ; i++){

		if(p[i] == ele){
		
			result1 = i;
			goto x;
		}

		else{
			result2 = -1;
		}			

	}

		x:
		return  (result1 == 0)? result2 :result1  ;
}

int main()
{

	unsigned long size = 5,i,pos;
	unsigned short a[5],ele;

	printf("enter array values :\n");

	for(i = 0;i < size; i++)
		scanf("%hd",&a[i]);
	printf("enter element :\n",ele);
	scanf("%hd",&ele);
	
	pos = position(size,a,ele);

	printf("pos : %ld\n",pos);

	return 0;
}
