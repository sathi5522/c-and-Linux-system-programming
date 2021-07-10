#include<stdio.h>
unsigned short year(unsigned short a)
{
	unsigned short x;
	x = a; 
	return x;
}
unsigned short month(unsigned short b)
{
	unsigned short z;
	z =  b << 7;
	return z;
}
unsigned short day(unsigned short c)
{
	unsigned short y;
	y =  c << 11;
	return y;
}


unsigned short read(unsigned short d)
{
        unsigned short x,y,z;
        x = (0x7f & d);
	
	y = (0xf100 & d) >> 11;
	
	z = (0x710 & d) >> 7;
	
	printf("%d : %d : %d \n",y,z,x);
}

int main()
{
        unsigned short dd = 24,mm = 6, yy =13;
	unsigned short d,h,k,m;

	m = year(yy);
	k = month(mm);
	h = day(dd);


	d = m | k | h;
        read(d);
        

        return 0;
}

