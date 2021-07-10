#include <stdio.h>

void  date(unsigned short int d, unsigned  short int m,unsigned  short int y)
{

	unsigned short int a;
	
	
	a = (( (y<<4) | m ) << 5) |d;
	bin(a);
	printf("%d : %d : %d",( a & 0x1f),((a>>5)&0xf),((a >> 9)&0x7f));
	

//	return a;
	

}

int main()
{

	unsigned short int dat,month,year;
	printf("date : \n month: \n year: \n");

	scanf("%hu%hu%hu",&dat,&month,&year);
	
	

	date(dat,month,year);

	return 0;
}
