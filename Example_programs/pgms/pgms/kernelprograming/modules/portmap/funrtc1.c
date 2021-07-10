#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include"rtc.h"
int init_module(void) {
        pr_info("module inserted\n");
	int s,m,h,d,m1,y,r;

	outb(SEC,COMMAND_REG);
	outb(0x20,DATA_REG);	
	READ_SEC(s);

	outb(MIN,COMMAND_REG);
	outb(0x30,DATA_REG);
	READ_MIN(m);

	outb(HRS,COMMAND_REG);
	outb(0x1,DATA_REG);
	READ_HRS(h);

	pr_info("hours: Min: sec: %x: %x: %x \n",h,m,s);


	READ_DAYNUMINWEEK(r);

	pr_info("day num in week:%x\n",r);

	READ_DAY(d);

	READ_MONTH(m1);

	READ_YEAR(y);

	pr_info("day: month: year: %x: %x: %x \n",d,m1,y);

        return 0;
}
void cleanup_module(void) {
        printk("module removed");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("rtc module");
MODULE_LICENSE("GPL");