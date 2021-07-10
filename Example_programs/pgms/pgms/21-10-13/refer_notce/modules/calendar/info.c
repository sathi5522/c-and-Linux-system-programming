#include"header.h"

int init_module(void)
{
	int sec,min,hour,day,date,month,year;
	pr_info("In init module inserted\n");

	READ_SEC(sec);
	READ_MIN(min);
	READ_HOUR(hour);
	READ_DAYNO(day);
	READ_DATE(date);
	READ_MONTH(month);
	READ_YEAR(year);

	pr_info("%x :- %x::%x::%x::%x::%x::%x\n",day,date,month,year,hour,min,sec);
	return 0;
}

void cleanup_module(void)
{
	pr_info("In cleanup module removed\n");
}

MODULE_AUTHOR("abc");
MODULE_DESCRIPTION("calendar");
MODULE_LICENSE("GPL");
