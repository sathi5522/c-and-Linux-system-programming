#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include"rtc.h"
int init_module(void) {
        pr_info("module inserted\n");
	int s,m,h,d,m1,y,r;

	outb(SEC,COMMAND_REG);
	s = inb(STATUS_REG);

	outb(MIN,COMMAND_REG);
	m = inb(STATUS_REG);

	outb(HRS,COMMAND_REG);
	h = inb(STATUS_REG);

	pr_info("hours: Min: sec: %x: %x: %x \n",h,m,s);


	outb(DAYNUMINWEEK,COMMAND_REG);
	r = inb(STATUS_REG);
	pr_info("day num in week:%x\n",r);

	outb(DAY,COMMAND_REG);
	d = inb(STATUS_REG);

	outb(MONTH,COMMAND_REG);
	m1 = inb(STATUS_REG);

	outb(YEAR,COMMAND_REG);
	y = inb(STATUS_REG);

	pr_info("day: month: year: %x: %x: %x \n",d,m1,y);

        return 0;
}
void cleanup_module(void) {
        printk("module removed");
}
MODULE_AUTHOR("satheesh");
MODULE_DESCRIPTION("rtc module");
MODULE_LICENSE("GPL");
