#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

void sum(void)
{
	int a = 10,b = 20;
	printk("sum :%d\n",a+b);
}

int init_module(void)
{
	pr_info("module inserted\n");
	return 0;
}

void cleanup_module(void)
{
	printk("module removed\n");
}

MODULE_AUTHOR("MAHESH");
MODULE_DESCRIPTION("SUM OF INTEGERS");
MODULE_LICENSE("GPL");

