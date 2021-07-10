#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
extern int c;
extern int sum(int,int);
int init_module(void) {

	c = sum(10,20);
        printk("module inserted\n");
	printk("in mod: the sum value:%d\n",c);
        return 0;
}

void cleanup_module(void) {
        printk("module removed\n");
}

MODULE_AUTHOR("sathi");
MODULE_DESCRIPTION("sum module");
MODULE_LICENSE("GPL");

