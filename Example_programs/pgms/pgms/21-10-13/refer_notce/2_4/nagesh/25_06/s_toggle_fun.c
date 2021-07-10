#include <stdio.h>
void bin(unsigned long int,short int);
void s_toggle(unsigned short int a,unsigned  short int pos_1, unsigned short int pos_2,unsigned short int pos_3)
{

	short int d = 1, result;

	pos_1 = d << (pos_1-1);
	pos_2 = d << (pos_2-1);
	pos_3 = d << (pos_3-1);

	result = a ^ pos_1 ^ pos_2 ^ pos_3;
	
	bin(result,sizeof(result));
}
