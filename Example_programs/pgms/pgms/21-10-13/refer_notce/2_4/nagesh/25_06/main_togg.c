#include <stdio.h>

void s_toggle(unsigned short,unsigned short ,unsigned short,unsigned short);
void bin(unsigned long int,short int);
int main(void)
{

	unsigned short int pos_1,pos_2,pos_3,data;

	printf("enter data \n ");
	scanf("%hu",&data);

	printf("enter pos 1 :\n");
	scanf("%hu",&pos_1);

	printf("enter pos_2 :\n");
	scanf("%hu",&pos_2);

	printf("enter pos_3 : \n");
	scanf("%hu",&pos_3);

	bin(data,sizeof(data));
	printf("\n");
	s_toggle(data,pos_1,pos_2,pos_3);


	return 0;

}
