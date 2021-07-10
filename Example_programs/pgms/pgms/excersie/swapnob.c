#include<stdio.h>
void swap(unsigned char a, unsigned char b, char pos,char nbits)
{
        unsigned char  y = 1, i,temp1,temp2;
        
        for(i = 1; i <= nbits-1; i++){
                y = y << 1;
                y = y | 1;
        }
        y = y << pos;
	temp1 = a & y;
	temp2 = b & y;
        y = ~y;
        a = a & y;
	a = a | temp2;
        b = b & y;
	b = b | temp1;
        print_bits(a,sizeof(a));
	print_bits(b,sizeof(b));

}

int main()
{
        unsigned char a = 10, b = 25;
        char pos = 2, nbits = 3;
        swap(a, b, pos, nbits);

        return 0;
}


