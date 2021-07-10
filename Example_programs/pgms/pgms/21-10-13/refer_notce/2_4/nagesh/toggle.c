#include <stdio.h>

void togg(unsigned short int a,unsigned short int b)
{

	unsigned short int c = 1,d;
	
	
	d = a ^ ( c<<(b-1));
	bin(d);
	
	

}

int main(void)
{

	unsigned short  int data,pos;

	printf("enter any data :\n position :\n");
	scanf("%hu%hu",&data,&pos);

	bin(data);
	togg(data,pos);
	
}
