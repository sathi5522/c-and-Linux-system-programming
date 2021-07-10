#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>

extern int value;

int init_module(void)
{
	pr_info("module inserted\n");
	value = 1000;
	return 0;
}

void cleanup_module(void)
{
	pr_info("module removed\n");
	pr_info("value :%d\n",value);
}

MODULE_AUTHOR("VEDA");
MODULE_DESCRIPTION("ACCESSING OTHER FILE DATA");
MODULE_LICENSE("GPL");
