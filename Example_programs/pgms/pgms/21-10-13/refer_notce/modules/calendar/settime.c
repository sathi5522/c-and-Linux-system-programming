#include"header.h"

int myinit(void)
{
	int sec = 0x20,min = 0x30,hour = 0x1,csec,cmin,chour;
	pr_info("In init module inserted\n");
	
	SET_SEC(sec)
	SET_MIN(min)
	SET_HOUR(hour)

	READ_SEC(csec);
	READ_MIN(cmin);
	READ_HOUR(chour);

	pr_info("%x:%x:%x\n",chour,cmin,csec);
	return 0;
}

void mycleanup(void)
{
	pr_info("In cleanup module removed\n");
}

module_init(myinit);
module_exit(mycleanup);

MODULE_AUTHOR("MAHESH");
MODULE_DESCRIPTION("SET THE TIME");
MODULE_LICENSE("GPL");
