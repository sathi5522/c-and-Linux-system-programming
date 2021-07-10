#include <stdio.h>

#define SET_D(yr,mn,d,result)	result = yr; \
				result = (result << 4)|mn; \
				result = (result << 5)|d;


#define GET_D(result)           printf("date  : %d \n", (result) & (0x0000001f));\
				printf("month : %d \n",(result >> 5) &(0x0000000f));\
				printf("year  : %d \n", (result >> 9) & (0x007fffff));


int main()
{

	unsigned short int date = 23, month = 10;
	unsigned int year = 90, ret_date;

	SET_D(year,month,date,ret_date)

	GET_D(ret_date)

	return 0; 

}
