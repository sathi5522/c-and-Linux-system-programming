#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

void Fun(void)
{
	printk("Hello world\n");
}

int init_module(void)
{
	printk("module inserted\n");
	return 0;
}

void cleanup_module(void)
{
	printk("module removed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAHESH");
MODULE_DESCRIPTION("FIRST MESSAGE");
